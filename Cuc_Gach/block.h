#pragma once
#include <map>
#include <vector>
#include "position.h"
#include "raylib.h"
class Block {
private:
	int cellSize;
	int rotationState;
	int rowOffset;
	int colOffset;
	std::vector<Color> color;
public:
	Block();
	int id;
	std::map<int, std::vector<Position>> cells;
	void draw();
	void move(int r, int c);
	std::vector<Position> getCellPositon();
	void rotate();
	void undoRotate();
};