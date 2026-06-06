#pragma once
#include "raylib.h"
#include <utility>
#include <cmath>
#define KING 1
#define QUEEN 2
#define ROOK 3
#define KNIGHT 4
#define BISHOP 5
#define PAWN 6
#define W 1
#define B -1
class Piece {
protected:
	int id;
	Texture2D image;
	int color;
	std::pair<int, int> pos;
public:
	int size;
	Piece() {
		size = 100;
	}
	~Piece() {
		UnloadTexture(image);
	}
	int getId() {
		return id;
	}
	int getColor() {
		return color;
	}
	void setPosition(std::pair<int, int> p) {
		pos = p;
	}
	std::pair<int, int>getPosition() {
		return pos;
	}
	virtual bool isValidMove(int r,int c) = 0;
	void draw(int x,int y) {
		DrawTexture(image, x, y, WHITE);
	}
};

class King :public Piece {
public:
	King(int color, std::pair<int, int> p) {
		pos = p;
		this->color = color;
		id = 1;
		if (color == W) {
			
			image = LoadTexture("Resource\\king.png");
		}
		else {
			image = LoadTexture("Resource\\king1.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c) override {
		int currRow = pos.first;
		int currCol = pos.second;

		// Kiểm tra xem vị trí mới có nằm trong phạm vi 1 ô xung quanh không
		if (abs(currRow - r) <= 1 && abs(currCol - c) <= 1) {
			// Kiểm tra xem ô mới có quân cờ cùng màu không
			return true;
		}

		return false;  // Nếu không thỏa điều kiện, nước đi không hợp lệ
	}
};
class Queen :public Piece {
public:
	Queen(int color, std::pair<int, int> p) {
		pos = p;
		this->color = color;
		id = 2;
		if (color == W) {
			image = LoadTexture("Resource\\queen.png");
		}
		else {
			image = LoadTexture("Resource\\queen1.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c) override{
		int curR = pos.first;
		int curC = pos.second;
		if ((curR == r && curC != c) || (curR != r && curC == c)) {
			return true;
		}
		if (abs(curR - r) == abs(curC - c)) {
			return true;
		}
		return false;
	}
};
class Rook :public Piece {
public:
	Rook(int color,std::pair<int,int> p) {
		pos = p;
		this->color = color;
		id = 3;
		if (color == W) {
			image = LoadTexture("Resource\\rook.png");
		}
		else {
			image = LoadTexture("Resource\\rook1.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c) override {
		int curR = pos.first;
		int curC = pos.second;
		if ((curR == r && curC != c) || (curR != r && curC == c)) {
			return true;
		}
		return false;
	}
};
class Knight :public Piece {
public:
	Knight(int color,std::pair<int, int> p) {
		pos = p;
		this->color = color;
		id = 4;
		if (color == W) {
			image = LoadTexture("Resource\\knight.png");
		}
		else {
			image = LoadTexture("Resource\\knight1.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c) override {
		int curR = pos.first;
		int curC = pos.second;
		if (r < 0 || r >= 8 || c < 0 || c >= 8)
			return false;
		if ((abs(curR - r) == 2 && abs(curC - c) == 1) || (abs(curR - r) == 1 && abs(curC - c) == 2)) {
			return true;
		}
		return false;
	}
};
class Bishop :public Piece {
public:
	Bishop(int color, std::pair<int, int> p) {
		pos = p;
		this->color = color;
		id = 5;
		if (color == W) {
			image = LoadTexture("Resource\\bishop.png");
		}
		else {
			image = LoadTexture("Resource\\bishop1.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c) override {
		int curR = pos.first;
		int curC = pos.second;
		if (curR == r && curC == c)
			return false;
		if (abs(curR - r) == abs(curC - c)) {
			return true;
		}
		return false;
	}
};
class Pawn :public Piece {
public:
	Pawn(int color, std::pair<int, int> p) {
		pos = p;
		this->color = color;
		id = 6;
		if (color == W) {
			image = LoadTexture("Resource\\pawn.png");
		}
		else {
			image = LoadTexture("Resource\\pawn1.png");
		}
		image.width = size;
		image.height = size;
	}
	bool isValidMove(int r, int c) override {
		int curR = pos.first;
		int curC = pos.second;

		if (color == W) {
			if (r - curR == 1)
				return true;
		}
		else {
			if (r - curR == -1)
				return true;
		}
		return false;
	}
};