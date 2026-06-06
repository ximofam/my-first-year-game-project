#include "Grid.h"


Grid::Grid() {
	grid = new int* [MAX_ROW];
	for (int i = 0; i < MAX_ROW; i++) {
		grid[i] = new int[MAX_COL];
		for (int j = 0; j < MAX_COL; j++) {
			grid[i][j] = 0;
		}
	}
}

Grid::~Grid() {
	for (int i = 0; i < MAX_ROW; i++) {
		delete[]grid[i];
	}
	delete[]grid;
}

void Grid::draw() {
	for (int i = 0; i <= MAX_ROW; i++) {
		DrawLine(0 + OFFSET_X, i * BLOCK_SIZE + OFFSET_Y, BLOCK_SIZE * MAX_COL + OFFSET_X, i * BLOCK_SIZE + OFFSET_Y, WHITE);
	}
	for (int j = 0; j <= MAX_COL; j++) {
		DrawLine(j * BLOCK_SIZE + OFFSET_X, 0 + OFFSET_Y, j * BLOCK_SIZE + OFFSET_X, BLOCK_SIZE * MAX_ROW + OFFSET_Y, WHITE);
	}

	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			if (grid[i][j])
				DrawRectangle(j * BLOCK_SIZE + OFFSET_X, i * BLOCK_SIZE + OFFSET_Y, BLOCK_SIZE - 1, BLOCK_SIZE - 1, Block::COLORS[grid[i][j]]);
		}
	}
}

void Grid::setPosGrid(Block* block) {
	vector<Position> positions = block->getPositions();
	for (auto& pos : positions) {
		grid[pos.row][pos.col] = block->getSign();
	}
}

void Grid::setPosGrid(vector<Position> positions, int sign) {
	for (auto& pos : positions) {
		grid[pos.row][pos.col] = sign;
	}
}

bool Grid::isValidMove(Block* block) {
	vector<Position> positions = block->getPositions();
	for (auto& pos : positions) {
		int r = pos.row;
		int c = pos.col;
		if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL || grid[r][c] != 0)
			return false;
	}
	return true;
}

bool Grid::isTouchBottom(Block* block) {
	for (auto& pos : block->getPositions()) {
		int r = pos.row;
		int c = pos.col;
		if (r >= MAX_ROW || grid[r][c] != 0) {
			return true;
		}
	}
	return false;
}

bool Grid::isTouchBottom(vector<Position>& positions) {
	for (auto& pos : positions) {
		int r = pos.row;
		int c = pos.col;
		if (r >= MAX_ROW || grid[r][c] != 0) {
			return true;
		}
	}
	return false;
}

bool Grid::isFullRow(int r) {
	for (int j = 0; j < MAX_COL; j++) {
		if (grid[r][j] == 0) return false;
	}
	return true;
}

void Grid::shiftDownRow(int r) {
	for (int j = 0; j < MAX_COL; j++) {
		grid[r][j] = 0;
	}

	int* temp = grid[r];

	for (int i = r; i > 0; i--) {
		grid[i] = grid[i - 1];
	}

	grid[0] = temp;
}