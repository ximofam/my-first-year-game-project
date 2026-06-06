#include "block.h"


Block::Block() {
	//id = 1;
	rowOffset = 0;
	colOffset = 0;
	cellSize = 30;
	rotationState = 0;
	color = { DARKGRAY,BLUE,YELLOW,ORANGE,PURPLE,RED,GREEN,WHITE };
}

void Block::draw() {
	std::vector<Position> tile = getCellPositon();
	for (Position item : tile) {
		DrawRectangle(item.c * cellSize + 1, item.r * cellSize + 1, cellSize - 1, cellSize - 1, color[id]);
	}
}

void Block::move(int r, int c) {
	rowOffset += r;
	colOffset += c;
}

std::vector<Position> Block::getCellPositon() {
	std::vector<Position> tile = cells[rotationState];
	std::vector<Position> res;
	for (Position item : tile) {
		Position New = { item.r + rowOffset,item.c + colOffset };
		res.push_back(New);
	}
	return res;
}

void Block::rotate() {
	rotationState = (rotationState + 1) % cells.size();
}
void Block::undoRotate() {
	rotationState = (rotationState + 3) % cells.size();
}