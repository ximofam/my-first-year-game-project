#include "Piece.h"


class King : public Piece {
public:
	King(PieceColor color) : Piece(color) {
		setTexture("Resource\\kingW.png", "Resource\\kingB.png");
		type = 'K';
	}
	bool isValidMove(Position pos) override {
		int rowDiff = ABS(this->pos.row - pos.row);
		int colDiff = ABS(this->pos.col - pos.col);
		return rowDiff <= 1 && colDiff <= 1;
	}
};

class Queen : public Piece {
public:
	Queen(PieceColor color) : Piece(color) {
		setTexture("Resource\\queenW.png", "Resource\\queenB.png");
		type = 'Q';
	}
	bool isValidMove(Position pos) override {
		int rowDiff = ABS(this->pos.row - pos.row);
		int colDiff = ABS(this->pos.col - pos.col);

		return this->pos.row == pos.row || this->pos.col == pos.col ||
			rowDiff == colDiff;
	}
};

class Rook : public Piece {
public:
	Rook(PieceColor color) : Piece(color) {
		setTexture("Resource\\rookW.png", "Resource\\rookB.png");
		type = 'R';
	}
	bool isValidMove(Position pos) override {
		return this->pos.row == pos.row || this->pos.col == pos.col;
	}
};

class Knight : public Piece {
public:
	Knight(PieceColor color) : Piece(color) {
		setTexture("Resource\\knightW.png", "Resource\\knightB.png");
		type = 'N';
	}
	bool isValidMove(Position pos) override {
		int rowDiff = ABS(this->pos.row - pos.row);
		int colDiff = ABS(this->pos.col - pos.col);
		return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
	}
};

class Bishop : public Piece {
public:
	Bishop(PieceColor color) : Piece(color) {
		setTexture("Resource\\bishopW.png", "Resource\\bishopB.png");
		type = 'B';
	}
	bool isValidMove(Position pos) override {
		int rowDiff = ABS(this->pos.row - pos.row);
		int colDiff = ABS(this->pos.col - pos.col);
		return rowDiff == colDiff;
	}
};

class Pawn : public Piece {
public:
	Pawn(PieceColor color) : Piece(color) {
		setTexture("Resource\\pawnW.png", "Resource\\pawnB.png");
		type = 'P';
	}
	bool isValidMove(Position pos) override {
		return true;
	}
};