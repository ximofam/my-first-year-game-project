#pragma once
#include "raylib.h"
#include "Config.h"
#include "Blocks.h"

class Grid {
private:
	int** grid;
public:
	Grid();
	~Grid();
	void draw();
	void setPosGrid(Block* block);
	void setPosGrid(vector<Position> positions, int sign);
	bool isValidMove(Block* block);
	bool isTouchBottom(Block* block);
	bool isTouchBottom(vector<Position>& positions);
	bool isFullRow(int row);
	void shiftDownRow(int row);
};