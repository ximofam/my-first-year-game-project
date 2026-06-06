#include "grid.h"

Grid::Grid() {
	row = 20;
	col = 10;
	cellSize = 30;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			grid[i][j] = 0;
		}
	}
	color = { DARKGRAY,BLUE,YELLOW,ORANGE,PURPLE,RED,GREEN,WHITE };
}


void Grid::draw() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, color[grid[i][j]]);
		}
	}
}

bool Grid::isOutSide(int r, int c) {
	if (r < 0 || r >= row || c < 0 || c >= col) {
		return true;
	}
	return false;
}

bool Grid::isCellEmpty(int r, int c) {
	if (grid[r][c] == 0) {
		return true;
	}
	return false;
}

bool Grid::isFullRow(int r) {
	for (int i = 0; i < col; i++) {
		if (grid[r][i] == 0)
			return false;
	}
	return true;
}

void Grid::clearRow(int r) {
	for (int c = 0; c < col; c++) {
		grid[r][c] = 0;
	}
}

void Grid::moveRowDown(int r, int to) {
	for (int c = 0; c < col; c++) {
		grid[r + to][c] = grid[r][c];
		grid[r][c] = 0;
	}
}

void Grid::clearFullRow() {
	int competed = 0;
	for (int r = row - 1; r >= 0; r--) {
		if (isFullRow(r)) {
			clearRow(r);
			competed++;
		}
		else if (competed > 0) {
			moveRowDown(r, competed);
		}
	}
}