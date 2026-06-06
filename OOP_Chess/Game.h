#pragma once
#include "Board.h"
#include "Player.h"
using namespace std;
class Game {
private:
	Board ChessBoard;
	Player p1 = Player(W);
	Player p2 = Player(B);
	Piece *selectedPiece;
	vector<pair<int, int>> PositionCanMove;
public:
	Game() {
		selectedPiece = NULL;
		setupBoard();
		setupPlayer(p1);
		setupPlayer(p2);
	}
	void setupBoard() {

		/*ChessBoard.placePiece(new Rook(W, { 0, 0 }), 0, 0);
		ChessBoard.placePiece(new Knight(W, { 0, 1 }), 0, 1);
		ChessBoard.placePiece(new Bishop(W, { 0, 2 }), 0, 2);
		ChessBoard.placePiece(new Queen(W, { 0,3 }), 0, 3);
		ChessBoard.placePiece(new King(W, { 0, 4 }), 0, 4);
		ChessBoard.placePiece(new Bishop(W, { 0, 5 }), 0, 5);
		ChessBoard.placePiece(new Knight(W, { 0,6 }), 0, 6);
		ChessBoard.placePiece(new Rook(W, { 0,7 }), 0, 7);
		for (int i = 0; i < 8; i++) {
			ChessBoard.placePiece(new Pawn(W, { 1,i }), 1, i);
		}


		ChessBoard.placePiece(new Rook(B, { 7,0 }), 7, 0);
		ChessBoard.placePiece(new Knight(B, { 7,1 }), 7, 1);
		ChessBoard.placePiece(new Bishop(B, { 7,2 }), 7, 2);
		ChessBoard.placePiece(new Queen(B, { 7,3 }), 7, 3);
		ChessBoard.placePiece(new King(B, { 7,4 }), 7, 4);
		ChessBoard.placePiece(new Bishop(B, { 7,5 }), 7, 5);
		ChessBoard.placePiece(new Knight(B, { 7,6 }), 7, 6);
		ChessBoard.placePiece(new Rook(B, { 7,7 }), 7, 7);
		for (int i = 0; i < 8; i++) {
			ChessBoard.placePiece(new Pawn(B, { 6,i }), 6, i);
		}*/
		ChessBoard.placePiece(new Queen(B, { 7,3 }), 7, 3);
	}
	void setupPlayer(Player& player) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				Piece* piece = ChessBoard.getPiece(i, j);
				if (piece != NULL && piece->getColor() == player.getColor()) {
					player.addPiece(piece);
				}
			}
		}
	}
	vector<pair<int, int>> getPositionCanMove(Piece *piece) {
		vector<pair<int, int>> res;
		pair<int, int> pos = piece->getPosition();
		switch (piece->getId()) {
		case KING:
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					int newR = pos.first + i;
					int newC = pos.second + j;
					if (piece->isValidMove(newR, newC) && ChessBoard.getPiece(newR, newC)->getColor() != piece->getColor()) {
						res.push_back({ newR,newC });
					}
				}
			}
			break;
		case QUEEN:
			//di ngang
			for (int i = pos.second + 1; i < 8; i++) {
				if (ChessBoard.getPiece(pos.first, i) == NULL) {
					res.push_back({ pos.first,i });
				}
				else {
					if (ChessBoard.getPiece(pos.first, i)->getColor() != piece->getColor()) {
						res.push_back({ pos.first,i });
					}
					break;
				}
			}
			for (int i = pos.second - 1; i >= 0; i--) {
				if (ChessBoard.getPiece(pos.first, i) == NULL) {
					res.push_back({ pos.first,i });
				}
				else {
					if (ChessBoard.getPiece(pos.first, i)->getColor() != piece->getColor()) {
						res.push_back({ pos.first,i });
					}
					break;
				}
			}
			//di thang
			for (int i = pos.first + 1; i < 8; i++) {
				if (ChessBoard.getPiece(i, pos.second) == NULL) {
					res.push_back({ i,pos.second });
				}
				else {
					if (ChessBoard.getPiece(i, pos.second)->getColor() != piece->getColor()) {
						res.push_back({ i,pos.second });
					}
					break;
				}
			}
			for (int i = pos.first - 1; i >= 0; i--) {
				if (ChessBoard.getPiece(i, pos.second) == NULL) {
					res.push_back({ i,pos.second });
				}
				else {
					if (ChessBoard.getPiece(i, pos.second)->getColor() != piece->getColor()) {
						res.push_back({ i,pos.second });
					}
					break;
				}
			}
			//di xeo
			for (int i = pos.first + 1, j = pos.second - 1; i < 8 && j >= 0; i++, j--) {
				if (ChessBoard.getPiece(i, j) == NULL) {
					res.push_back({ i,j });
				}
				else {
					if (ChessBoard.getPiece(i, j)->getColor() != piece->getColor()) {
						res.push_back({ i,j });
					}
					break;
				}
			}
			for (int i = pos.first - 1, j = pos.second + 1; i >= 0 && j < 8; i--, j++) {
				if (ChessBoard.getPiece(i, j) == NULL) {
					res.push_back({ i,j });
				}
				else {
					if (ChessBoard.getPiece(i, j)->getColor() != piece->getColor()) {
						res.push_back({ i,j });
					}
					break;
				}
			}
			for (int i = pos.first + 1, j = pos.second + 1; i < 8 && j < 8; i++, j++) {
				if (ChessBoard.getPiece(i, j) == NULL) {
					res.push_back({ i,j });
				}
				else {
					if (ChessBoard.getPiece(i, j)->getColor() != piece->getColor()) {
						res.push_back({ i,j });
					}
					break;
				}
			}
			for (int i = pos.first - 1, j = pos.second - 1; i >= 0 && j >= 0; i--, j--) {
				if (ChessBoard.getPiece(i, j) == NULL) {
					res.push_back({ i,j });
				}
				else {
					if (ChessBoard.getPiece(i, j)->getColor() != piece->getColor()) {
						res.push_back({ i,j });
					}
					break;
				}
			}

			break;
		case ROOK:
			//di ngang
			for (int i = pos.second + 1; i < 8; i++) {
				if (ChessBoard.getPiece(pos.first, i) == NULL) {
					res.push_back({ pos.first,i });
				}
				else {
					if (ChessBoard.getPiece(pos.first, i)->getColor() != piece->getColor()) {
						res.push_back({ pos.first,i });
					}
					break;
				}
			}
			for (int i = pos.second - 1; i >= 0; i--) {
				if (ChessBoard.getPiece(pos.first, i) == NULL) {
					res.push_back({ pos.first,i });
				}
				else {
					if (ChessBoard.getPiece(pos.first, i)->getColor() != piece->getColor()) {
						res.push_back({ pos.first,i });
					}
					break;
				}
			}
			//di thang
			for (int i = pos.first + 1; i < 8; i++) {
				if (ChessBoard.getPiece(i, pos.second) == NULL) {
					res.push_back({ i,pos.second });
				}
				else {
					if (ChessBoard.getPiece(i, pos.second)->getColor() != piece->getColor()) {
						res.push_back({ i,pos.second });
					}
					break;
				}
			}
			for (int i = pos.first - 1; i >= 0; i--) {
				if (ChessBoard.getPiece(i, pos.second) == NULL) {
					res.push_back({ i,pos.second });
				}
				else {
					if (ChessBoard.getPiece(i, pos.second)->getColor() != piece->getColor()) {
						res.push_back({ i,pos.second });
					}
					break;
				}
			}
			break;
		case KNIGHT:
			for (int i = pos.first - 2; i <= pos.first + 2; i++) {
				for (int j = pos.second - 2; j <= pos.second + 2; j++) {
					if (piece->isValidMove(i, j) && ChessBoard.getPiece(i, j) == NULL && ChessBoard.getPiece(i, j)->getColor() != piece->getColor()) {
						res.push_back({ i,j });
					}
				}
			}
			break;
		case BISHOP:
			for (int i = pos.first + 1, j = pos.second - 1; i < 8 && j >= 0; i++, j--) {
				if (ChessBoard.getPiece(i, j) == NULL) {
					res.push_back({ i,j });
				}
				else {
					if (ChessBoard.getPiece(i, j)->getColor() != piece->getColor()) {
						res.push_back({ i,j });
					}
					break;
				}
			}
			for (int i = pos.first - 1, j = pos.second + 1; i >= 0 && j < 8; i--, j++) {
				if (ChessBoard.getPiece(i, j) == NULL) {
					res.push_back({ i,j });
				}
				else {
					if (ChessBoard.getPiece(i, j)->getColor() != piece->getColor()) {
						res.push_back({ i,j });
					}
					break;
				}
			}
			for (int i = pos.first + 1, j = pos.second + 1; i < 8 && j < 8; i++, j++) {
				if (ChessBoard.getPiece(i, j) == NULL) {
					res.push_back({ i,j });
				}
				else {
					if (ChessBoard.getPiece(i, j)->getColor() != piece->getColor()) {
						res.push_back({ i,j });
					}
					break;
				}
			}
			for (int i = pos.first - 1, j = pos.second - 1; i >= 0 && j >= 0; i--, j--) {
				if (ChessBoard.getPiece(i, j) == NULL) {
					res.push_back({ i,j });
				}
				else {
					if (ChessBoard.getPiece(i, j)->getColor() != piece->getColor()) {
						res.push_back({ i,j });
					}
					break;
				}
			}
			break;
		case PAWN:
			break;
		}
		return res;
	}
	void update() {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Vector2 mousePos = GetMousePosition();
			int c = mousePos.x / ChessBoard.sizeOneBlock;
			int r = mousePos.y / ChessBoard.sizeOneBlock;
			if (ChessBoard.getPiece(r,c) != NULL) {
				selectedPiece = ChessBoard.getPiece(r, c);
				PositionCanMove = getPositionCanMove(selectedPiece);
			}
			cout << "Da tro vao\n";
		}
	}
	void render() {
		BeginDrawing();
		ChessBoard.draw();
		if (selectedPiece != NULL) {
			cout << "Bat dau ve";
			for (auto pos : PositionCanMove) {
				DrawCircle(pos.second+ChessBoard.sizeOneBlock/2, pos.first + ChessBoard.sizeOneBlock / 2, 10, RED);
			}
		}
		EndDrawing();
	}
};