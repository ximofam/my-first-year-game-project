#pragma once
#include "raylib.h"
#include "Position.h"
#include <cmath>
enum PieceType {
	king, queen, rook, knight, bishop, pawn, none
};
enum PieceColor {
	white, black
};

class Piece {
protected:
	PieceType type;
	PieceColor color;
	Texture2D image;
	Position pos;
public:
	int size;
	Piece() {
		pos = { -10,-10 };
		size = 100;
	}
	~Piece() {
		UnloadTexture(image);
	}
	PieceType getType() {
		return type;
	}
	PieceColor getColor() {
		return color;
	}
	Position getPosition() {
		return pos;
	}
	void setPosition(Position pos) {
		this->pos = pos;
	}
	virtual bool isValidMove(int r, int c, Piece* piece) = 0;
	void draw() {
		DrawTexture(image, pos.c * size, pos.r * size, WHITE);
	}
};

class King :public Piece {
public:
	King(PieceColor color) {
		this->color = color;
		//this->pos = pos;
		type = king;
		if (color == white) {
			image = LoadTexture("resource\\kingW.png");
		}
		else {
			image = LoadTexture("resource\\kingB.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c, Piece* piece) override {
		if ((pos.r == r && pos.c == c))
			return false;
		if (abs(pos.r - r) <= 1 && abs(pos.c - c) <= 1) {
			if (piece == NULL || piece->getColor() != color)
				return true;
		}

		return false;
	}
};

class Queen :public Piece {
public:
	Queen(PieceColor color) {
		this->color = color;
		//this->pos = pos;
		type = queen;
		if (color == white) {
			image = LoadTexture("resource\\queenW.png");
		}
		else {
			image = LoadTexture("resource\\queenB.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c, Piece* piece) override {
		if ((pos.r == r && pos.c == c))
			return false;
		if ((pos.r == r) || (pos.c == c) || (abs(pos.r - r) == abs(pos.c - c))) {
			if (piece == NULL && piece->getColor() != color)
				return true;
		}

		return false;
	}
};

class Rook :public Piece {
public:
	Rook(PieceColor color) {
		this->color = color;
		//this->pos = pos;
		type = rook;
		if (color == white) {
			image = LoadTexture("resource\\rookW.png");
		}
		else {
			image = LoadTexture("resource\\rookB.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c, Piece* piece) override {
		if ((pos.r == r && pos.c == c))
			return false;
		if ((pos.r == r) || (pos.c == c)) {
			if (piece == NULL || piece->getColor() != color)
				return true;
		}

		return false;
	}
};

class Knight :public Piece {
public:
	Knight(PieceColor color) {
		this->color = color;
		//this->pos = pos;
		type = knight;
		if (color == white) {
			image = LoadTexture("resource\\knightW.png");
		}
		else {
			image = LoadTexture("resource\\knightB.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c, Piece* piece) override {
		if ((pos.r == r && pos.c == c))
			return false;
		int diffR = abs(pos.r - r);
		int diffC = abs(pos.c - c);
		if ((diffR == 2 && diffC == 1) || (diffR == 1 && diffC == 2)) {
			if (piece == NULL || piece->getColor() != color)
				return true;
		}

		return false;
	}
};

class Bishop :public Piece {
public:
	Bishop(PieceColor color) {
		this->color = color;
		//this->pos = pos;
		type = bishop;
		if (color == white) {
			image = LoadTexture("resource\\bishopW.png");
		}
		else {
			image = LoadTexture("resource\\bishopB.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c, Piece* piece) override {
		if ((pos.r == r && pos.c == c))
			return false;
		if (abs(pos.r - r) == abs(pos.c - c)) {
			if (piece == NULL || piece->getColor() != color)
				return true;
		}

		return false;
	}
};

class Pawn :public Piece {
public:
	Pawn(PieceColor color) {
		this->color = color;
		//this->pos = pos;
		type = pawn;
		if (color == white) {
			image = LoadTexture("resource\\pawnW.png");
		}
		else {
			image = LoadTexture("resource\\pawnB.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c, Piece* piece) override {
		if ((pos.r == r && pos.c == c))
			return false;
		int diffR = color == black ? r - pos.r : pos.r - r;
		if (diffR == 1) {
			if (piece == NULL && pos.c == c)
				return true;
			else if (piece != NULL && abs(pos.c - c) == 1 && piece->getColor() != color)
				return true;
		}
		return false;
	}
};