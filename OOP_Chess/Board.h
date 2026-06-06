#pragma once
#include "Piece.h"
#include <iostream>
class Board {
private:
	Piece* board[8][8];
public:
	int sizeOneBlock;
	Board() {
		sizeOneBlock = 100;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				board[i][j] = NULL;
			}
		}
	}
	void placePiece(Piece* piece, int r, int c) {
		board[r][c] = piece;
	}
	void move(int r, int c, int desR, int desC) {
		if (board[desR][desC] != NULL) {
			delete board[desR][desC];
		}
		board[desR][desC] = board[r][c];
		board[desR][desC]->setPosition({ desR,desC });
		board[r][c] = NULL;
	}

	~Board() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				delete board[i][j];
			}
		}
		std::cout << "Da giai phong vung nho!!\n";
	}
	Piece* getPiece(int r, int c) {
		return board[r][c];
	}

	void draw() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
					DrawRectangle(j * sizeOneBlock, i * sizeOneBlock, sizeOneBlock, sizeOneBlock, RAYWHITE);
				}
				else {
					DrawRectangle(j * sizeOneBlock, i * sizeOneBlock, sizeOneBlock, sizeOneBlock, DARKBROWN);
				}

				if (board[i][j] != NULL) {
					board[i][j]->draw(j * sizeOneBlock, i * sizeOneBlock);
				}
			}
		}
	}
};