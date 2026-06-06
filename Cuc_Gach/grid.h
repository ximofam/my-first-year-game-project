#pragma once
#include "raylib.h"
#include <vector>

class Grid {
private:
	int row, col;
	int cellSize;
	std::vector<Color> color;
	
public:
	int grid[20][10];
	Grid();
	void draw();
	bool isOutSide(int r, int c);
	bool isCellEmpty(int r, int c);
	bool isFullRow(int r);
	void clearRow(int r);
	void moveRowDown(int r, int to);
	void clearFullRow();
};
