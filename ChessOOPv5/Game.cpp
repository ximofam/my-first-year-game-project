#include "Logic.cpp"
#include <iostream>


class Game {
private:
	Board* board;
	Piece* selectedPiece;
	vector<Position> positions;
	void setupBoard() {
		board->placePiece({ 0, 0 }, new Rook(white));
		board->placePiece({ 0, 1 }, new Knight(white));
		board->placePiece({ 0, 2 }, new Bishop(white));
		board->placePiece({ 0, 3 }, new Queen(white));
		board->placePiece({ 0, 4 }, new King(white));
		board->placePiece({ 0, 5 }, new Bishop(white));
		board->placePiece({ 0, 6 }, new Knight(white));
		board->placePiece({ 0, 7 }, new Rook(white));
		/*for (int i = 0; i < 8; i++) {
			board->placePiece({ 1, i }, new Pawn(white));
		}*/

		board->placePiece({ 7, 0 }, new Rook(black));
		board->placePiece({ 7, 1 }, new Knight(black));
		board->placePiece({ 7, 2 }, new Bishop(black));
		board->placePiece({ 7, 3 }, new Queen(black));
		board->placePiece({ 7, 4 }, new King(black));
		board->placePiece({ 7, 5 }, new Bishop(black));
		board->placePiece({ 7, 6 }, new Knight(black));
		board->placePiece({ 7, 7 }, new Rook(black));
		/*for (int i = 0; i < 8; i++) {
			board->placePiece({ 6, i }, new Pawn(black));
		}*/
	}
public:
	Game() {
		selectedPiece = NULL;
		board = new Board();


		setupBoard();
	}
	~Game() {
		delete board;
	}

	void update() {
		if (selectedPiece == NULL && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			Vector2 pos = GetMousePosition();
			selectedPiece = board->getPiece({ int(pos.y / BLOCK_SIZE), int(pos.x / BLOCK_SIZE) });
			if (selectedPiece) {
				std::cout << "Da chon quan co\n";
				positions = Logic::getPosCanMove(board, selectedPiece);
			}

		}
		else if (selectedPiece != NULL && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			Vector2 pos = GetMousePosition();
			Position newPos = { int(pos.y / BLOCK_SIZE), int(pos.x / BLOCK_SIZE) };

			for (auto& pos : positions) {
				if (newPos.row == pos.row && newPos.col == pos.col)
					board->movePiece(selectedPiece, newPos);
			}
			
			selectedPiece = NULL;
			positions.clear();
		}
	}

	void draw() {
		BeginDrawing();

		board->draw();

		for (auto& pos : positions) {
			int radius = 10;
			int r = pos.row * BLOCK_SIZE + BLOCK_SIZE / 2;
			int c = pos.col * BLOCK_SIZE + BLOCK_SIZE / 2;
			DrawCircle(c, r, radius, RED);
		}

		EndDrawing();
	}
};




