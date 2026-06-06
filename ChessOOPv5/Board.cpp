#include "Board.h"
#include <iostream>
using namespace std;


Board::Board() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = NULL;
		}
	}
}

Board::~Board() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] != NULL)
				delete board[i][j];
		}
	}
	cout << "Da giai phong ban co";
}

void Board::draw() {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if ((i + j) % 2 != 0) {
				DrawRectangle(i * BLOCK_SIZE, j * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, WHITE);
			}
			else {
				DrawRectangle(i * BLOCK_SIZE, j * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, BROWN);
			}
		}
	}


	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] != NULL) board[i][j]->draw();
		}
	}
}

void Board::placePiece(Position pos, Piece* piece) {
	piece->setPosition(pos);
	board[pos.row][pos.col] = piece;
}

void Board::movePiece(Piece* piece, Position newPos) {
	if (isValidMove(piece, newPos) == 0) return;

	deletePiece(newPos);

	Position pos = piece->getPosition();
	placePiece(newPos, piece);

	board[pos.row][pos.col] = NULL;
}

Piece* Board::getPiece(Position pos) {
	return board[pos.row][pos.col];
}

bool Board::isOutSite(Position pos) {
	int r = pos.row;
	int c = pos.col;
	return r < 0 || r >= SIZE || c < 0 || c >= SIZE;
}

void Board::deletePiece(Position pos) {
	int r = pos.row, c = pos.col;
	if (board[r][c] != NULL) {
		delete board[r][c];
		board[r][c] = NULL;
	}
}

int Board::isValidMove(Piece* piece, Position pos) {
	if (isOutSite(pos) || piece->isValidMove(pos) == false) return 0;
	if (piece->getPosition().row == pos.row && piece->getPosition().col == pos.col)
		return 0;

	if (getPiece(pos) != NULL) {
		if (piece->getColor() != getPiece(pos)->getColor())
			return -1;
		else return 0;
	}
	return 1;
}