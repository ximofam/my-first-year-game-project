#pragma once
#include "Pieces.cpp"


class Board {
private:
	Piece* board[SIZE][SIZE];
public:
	Board();
	~Board();
	void draw();
	void placePiece(Position pos, Piece* piece);
	void movePiece(Piece* piece, Position newPos);
	int isValidMove(Piece* piece, Position newPos);
	Piece* getPiece(Position pos);
	bool isOutSite(Position pos);
	void deletePiece(Position pos);
};

