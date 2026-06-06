#pragma once
#include "Piece.h"

class Board{
private:
	Piece* board[8][8];
public:
	int size;
	Board() {
		size = 100;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				board[i][j] = NULL;
			}
		}
	}
	~Board() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				delete board[i][j];
			}
		}
	}
	void makeMove(int startR, int startC, int endR, int endC) {
		if (board[endR][endC] != NULL) {
			delete board[endR][endC];
		}
		board[endR][endC] = board[startR][startC];
		board[endR][endC]->setPosition({ endR,endC });
		board[startR][startC] = NULL;
	}
	void setPiece(int r, int c, Piece* piece) {
		piece->setPosition({ r,c });
		board[r][c] = piece;
	}
	Piece* getPiece(int r, int c) {
		return board[r][c];
	}
	void draw() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				Color color = ((i + j) % 2 == 0 ? LIGHTGRAY : DARKBROWN);
				DrawRectangle(j * size, i * size, size, size, color);

				if (board[i][j] != NULL) {
					board[i][j]->draw();
				}
			}
		}
	}
};