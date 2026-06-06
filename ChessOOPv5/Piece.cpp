#include "Piece.h"

Piece::Piece(PieceColor color) {
	this->color = color;
	pos = { -100, -100 };
}
Piece::~Piece() {
	UnloadTexture(image);
}

void Piece::draw() {
	DrawTexture(image, pos.col * BLOCK_SIZE, pos.row * BLOCK_SIZE, WHITE);
}

void Piece::setTexture(const char* sourceW, const char* sourceB) {
	if (color == white) {
		image = LoadTexture(sourceW);
	}
	else {
		image = LoadTexture(sourceB);
	}
	image.width = BLOCK_SIZE;
	image.height = BLOCK_SIZE;
}

void Piece::setPosition(Position pos) {
	this->pos = pos;
}

Position Piece::getPosition() {
	return this->pos;
}

PieceColor Piece::getColor() {
	return this->color;
}

char Piece::getType() { return type; }