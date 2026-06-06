#include "Logic.cpp";

class Game {
private:
	Board* board;
public:
	Game() {
		board = new Board(8);
		setupBoard();
	}
	~Game() {
		delete board;
	}


	void update() {

	}

	void render() {
		board->draw();
	}








	void setupBoard() {
		board->placePiece(new Rook(WHITE), 7, 0);
		board->placePiece(new Knight(WHITE), 7, 1);
		board->placePiece(new Bishop(WHITE), 7, 2);
		board->placePiece(new Queen(WHITE), 7, 3);
		board->placePiece(new King(WHITE), 7, 4);
		board->placePiece(new Bishop(WHITE), 7, 5);
		board->placePiece(new Knight(WHITE), 7, 6);
		board->placePiece(new Rook(WHITE), 7, 7);
		for (int i = 0; i < board->getSize(); i++) {
			board->placePiece(new Pawn(WHITE), 6, i);
		}

		board->placePiece(new Rook(BLACK), 0, 0);
		board->placePiece(new Knight(BLACK), 0, 1);
		board->placePiece(new Bishop(BLACK), 0, 2);
		board->placePiece(new Queen(BLACK), 0, 3);
		board->placePiece(new King(BLACK), 0, 4);
		board->placePiece(new Bishop(BLACK), 0, 5);
		board->placePiece(new Knight(BLACK), 0, 6);
		board->placePiece(new Rook(BLACK), 0, 7);
		for (int i = 0; i < board->getSize(); i++) {
			board->placePiece(new Pawn(BLACK), 1, i);
		}
	}
};