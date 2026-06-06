#pragma once
#include "Position.h"
#include "raylib.h"
#include "Config.h"
#include "PieceColor.h"


class Piece {
private:
	Texture2D image;
protected:
	Position pos;
	PieceColor color;
	char type;
public:
	Piece(PieceColor color);
	~Piece();
	void draw();
	void setTexture(const char* sourceW, const char* sourceB);
	void setPosition(Position pos);
	Position getPosition();
	virtual bool isValidMove(Position pos) = 0;
	PieceColor getColor();
	char getType();
};