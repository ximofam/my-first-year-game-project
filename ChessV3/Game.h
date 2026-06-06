#pragma once
#include "raylib.h"
#include "Board.h"
#include <iostream>
#include <vector>
using namespace std;
class Game {
private:
	Board ChessBoard;
	Piece* selectedPiece;
	vector<Position> PositionCanMove;
	vector<Position> getPositionCanMove() {
		vector<Position> res;
		int r = selectedPiece->getPosition().r;
		int c = selectedPiece->getPosition().c;
		if (selectedPiece->getType() == king) {
			for (int i = r - 1; i <= r + 1; i++) {
				for (int j = c - 1; j <= c + 1; j++) {
					if (i >= 0 && i < 8 && j >= 0 && j < 8) {
						if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
							res.push_back({ i,j });
					}
				}
			}
		}
		else if (selectedPiece->getType() == queen) {
			//di thang
			for (int i = r + 1; i < 8; i++) {
				if (selectedPiece->isValidMove(i, c, ChessBoard.getPiece(i, c)))
					res.push_back({ i,c });
				else break;
			}
			for (int i = r - 1; i >=0; i--) {
				if (selectedPiece->isValidMove(i, c, ChessBoard.getPiece(i, c)))
					res.push_back({ i,c });
				else break;
			}
			//di ngang
			for (int i = c + 1; i < 8; i++) {
				if (selectedPiece->isValidMove(r, i, ChessBoard.getPiece(r, i)))
					res.push_back({ r,i });
				else break;
			}
			for (int i = c - 1; i >= 0; i--) {
				if (selectedPiece->isValidMove(r, i, ChessBoard.getPiece(r, i)))
					res.push_back({ r,i });
				else break;
			}
			//di xeo
			int i, j;
			i = r + 1; j = c - 1;
			while (i >= 0 && i < 8 && j >= 0 && j < 8) {
				if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
					res.push_back({ i,j });
				else break;
				i++;
				j--;
			}
			i = r - 1; j = c + 1;
			while (i >= 0 && i < 8 && j >= 0 && j < 8) {
				if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
					res.push_back({ i,j });
				else break;
				i--;
				j++;
			}
			i = r + 1; j = c + 1;
			while (i >= 0 && i < 8 && j >= 0 && j < 8) {
				if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
					res.push_back({ i,j });
				else break;
				i++;
				j++;
			}
			i = r - 1; j = c - 1;
			while (i >= 0 && i < 8 && j >= 0 && j < 8) {
				if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
					res.push_back({ i,j });
				else break;
				i--;
				j--;
			}
		}
		else if (selectedPiece->getType() == rook) {
			//di thang
			for (int i = r + 1; i < 8; i++) {
				if (selectedPiece->isValidMove(i, c, ChessBoard.getPiece(i, c)))
					res.push_back({ i,c });
				else break;
			}
			for (int i = r - 1; i >= 0; i--) {
				if (selectedPiece->isValidMove(i, c, ChessBoard.getPiece(i, c)))
					res.push_back({ i,c });
				else break;
			}
			//di ngang
			for (int i = c + 1; i < 8; i++) {
				if (selectedPiece->isValidMove(r, i, ChessBoard.getPiece(r, i)))
					res.push_back({ r,i });
				else break;
			}
			for (int i = c - 1; i >= 0; i--) {
				if (selectedPiece->isValidMove(r, i, ChessBoard.getPiece(r, i)))
					res.push_back({ r,i });
				else break;
			}
		}
		else if (selectedPiece->getType() == knight) {
			for (int i = r - 2; i <= r + 2; i++) {
				for (int j = c - 2; j < c + 2; j++) {
					if (i >= 0 && i < 8 && j >= 0 && j < 8) {
						if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
							res.push_back({ i,j });
					}
				}
			}
		}
		else if (selectedPiece->getType() == bishop) {
			//di xeo
			int i, j;
			i = r + 1; j = c - 1;
			while (i >= 0 && i < 8 && j >= 0 && j < 8) {
				if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
					res.push_back({ i,j });
				else break;
				i++;
				j--;
			}
			i = r - 1; j = c + 1;
			while (i >= 0 && i < 8 && j >= 0 && j < 8) {
				if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
					res.push_back({ i,j });
				else break;
				i--;
				j++;
			}
			i = r + 1; j = c + 1;
			while (i >= 0 && i < 8 && j >= 0 && j < 8) {
				if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
					res.push_back({ i,j });
				else break;
				i++;
				j++;
			}
			i = r - 1; j = c - 1;
			while (i >= 0 && i < 8 && j >= 0 && j < 8) {
				if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
					res.push_back({ i,j });
				else break;
				i--;
				j--;
			}
		}
		else if (selectedPiece->getType() == pawn) {
			for (int i = r - 1; i <= r + 1; i++) {
				for (int j = c - 1; j <= c + 1; j++) {
					if (i >= 0 && i < 8 && j >= 0 && j < 8) {
						if (selectedPiece->isValidMove(i, j, ChessBoard.getPiece(i, j)))
							res.push_back({ i,j });
					}
				}
			}
		}
		return res;
	}
public:
	Game() {
		selectedPiece = NULL;
		setupBoard();
	}
	void setupBoard() {
		/*int board[8][8] = { rook, knight, bishop , queen , king,  bishop,  knight , rook,
							pawn,  pawn,  pawn,pawn , pawn,  pawn,  pawn,  pawn,
							none,  none,  none,  none,  none,  none,  none,  none,
							none,  none,  none,  none,  none,  none,  none,  none,
							none,  none,  none,  none,  none,  none,  none,  none,
							none,  none,  none,  none,  none,  none,  none,  none,
							pawn,  pawn,  pawn,pawn , pawn,  pawn,  pawn,  pawn,
							rook, knight, bishop , queen , king,  bishop,  knight , rook
		};*/
		ChessBoard.setPiece(0, 0, new Rook(black));
		ChessBoard.setPiece(0, 1, new Knight(black));
		ChessBoard.setPiece(0, 2, new Bishop(black));
		ChessBoard.setPiece(0, 3, new Queen(black));
		ChessBoard.setPiece(0, 4, new King(black));
		ChessBoard.setPiece(0, 5, new Bishop(black));
		ChessBoard.setPiece(0, 6, new Knight(black));
		ChessBoard.setPiece(0, 7, new Rook(black));
		for (int i = 0; i < 8; i++) {
			ChessBoard.setPiece(1, i, new Pawn(black));
		}
		ChessBoard.setPiece(7, 0, new Rook(white));
		ChessBoard.setPiece(7, 1, new Knight(white));
		ChessBoard.setPiece(7, 2, new Bishop(white));
		ChessBoard.setPiece(7, 3, new Queen(white));
		ChessBoard.setPiece(7, 4, new King(white));
		ChessBoard.setPiece(7, 5, new Bishop(white));
		ChessBoard.setPiece(7, 6, new Knight(white));
		ChessBoard.setPiece(7, 7, new Rook(white));
		for (int i = 0; i < 8; i++) {
			ChessBoard.setPiece(6, i, new Pawn(white));
		}
	}
	void update() {
		if (selectedPiece==NULL&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Vector2 mouse = GetMousePosition();
			int selectedR = (int)mouse.y / ChessBoard.size;
			int selectedC =(int)mouse.x / ChessBoard.size;
			if (ChessBoard.getPiece(selectedR, selectedC) != NULL) {
				selectedPiece = ChessBoard.getPiece(selectedR, selectedC);
				PositionCanMove = getPositionCanMove();
				cout << "Da tro\n";
			}
		}
		else if (selectedPiece != NULL && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			int r = (int)GetMousePosition().y/ChessBoard.size;
			int c = (int)GetMousePosition().x/ChessBoard.size;
			for (auto pos : PositionCanMove) {
				if (r == pos.r && pos.c == c) {
					Position curPiece = selectedPiece->getPosition();
					ChessBoard.makeMove(curPiece.r, curPiece.c, pos.r, pos.c);
					break;
				}
			}
			selectedPiece = NULL;
		}
	}
	void render() {
		BeginDrawing();
		ChessBoard.draw();
		if (selectedPiece != NULL) {
			for (auto pos : PositionCanMove) {
				DrawCircle(pos.c * ChessBoard.size+ChessBoard.size/2, pos.r * ChessBoard.size+ChessBoard.size/2, 10, RED);
			}
		}
		EndDrawing();
	}
};