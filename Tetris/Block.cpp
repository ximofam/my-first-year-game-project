#include "Block.h"

void Block::init() {
	state = 0;
	offsetRow = 0;
	offsetCol = MAX_COL / 2 - 2;
}

Block::Block() {
	init();
}


void Block::draw() {
	for (auto& pos : getPositions()) {
		DrawRectangle(pos.col * BLOCK_SIZE + OFFSET_X, pos.row * BLOCK_SIZE + OFFSET_Y, BLOCK_SIZE - 1, BLOCK_SIZE - 1, color);
	}
}

void Block::rotateRight() {
	if (state == 3) {
		state = 0;
	}
	else {
		state++;
	}
}

void Block::rotateLeft() {
	if (state == 0) {
		state = 3;
	}
	else {
		state--;
	}
}

vector<Position> Block::getPositions() {
	vector<Position> res;
	for (Position& pos : cells[state]) {
		res.push_back({ offsetRow + pos.row, offsetCol + pos.col });
	}
	return res;
}

const vector<Color> Block::COLORS = { BG_COLOR, RED, YELLOW, GREEN, BLUE, PURPLE, ORANGE, DARKGREEN };

void Block::moveUp() {
	offsetRow--;
}

void Block::moveDown() {
	offsetRow++;
}

void Block::moveLeft() {
	offsetCol--;
}

void Block::moveRight() {
	offsetCol++;
}

int Block::getSign() {
	return SIGN;
}

vector<Position> Block::getMatrix() {
	return cells[state];
}

Color Block::getColor() {
	return color;
}