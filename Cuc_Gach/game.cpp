#include "game.h"
#include <random>

Game::Game() {
	gameOver = false;
	grid = Grid();
	blocks = getAllBlock();
	current = getRandomBlock();
	next = getRandomBlock();
}

std::vector<Block> Game::getAllBlock() {
	return { IBlock(),OBlock(),ZBlock(),LBlock(),TBlock(),SBlock(),JBlock() };
}

Block Game::getRandomBlock() {
	srand(time(NULL));
	if (blocks.empty()) {
		blocks = getAllBlock();
	}
	int index = rand() % blocks.size();
	Block block = blocks[index];
	blocks.erase(blocks.begin() + index);
	return block;
}

void Game::draw() {
	BeginDrawing();
	grid.draw();
	current.draw();
	EndDrawing();
}

void Game::handleInput() {
	int key = GetKeyPressed();
	if (gameOver && key != 0) {
		reset();
	}
	switch (key) {
	case KEY_LEFT:
		moveLeft();
		break;
	case KEY_RIGHT:
		moveRight();
		break;
	case KEY_UP:
		rotateBlock();
		break;
	case KEY_DOWN:
		moveDown();
		break;
	}


}

void Game::moveLeft() {
	if (gameOver == false) {
		current.move(0, -1);
		if (isBlockOutside() || blockFit() == false) {
			current.move(0, 1);
		}
	}
}
void Game::moveRight() {
	if (gameOver == false) {
		current.move(0, 1);
		if (isBlockOutside() || blockFit() == false) {
			current.move(0, -1);
		}
	}
	
}
void Game::moveDown() {
	if (gameOver == false) {
		current.move(1, 0);
		if (isBlockOutside() || blockFit() == false) {
			current.move(-1, 0);
			lockBlock();
			grid.clearFullRow();
		}
	}
	
}
void Game::rotateBlock() {
	if (gameOver == false) {
		current.rotate();
		if (isBlockOutside() || blockFit() == false) {
			current.undoRotate();
		}
	}
}

bool Game::isBlockOutside() {
	std::vector<Position> tiles = current.getCellPositon();
	for (Position item : tiles) {
		if (grid.isOutSide(item.r, item.c))
			return true;
	}
	return false;
}
bool Game::blockFit() {
	std::vector<Position> tiles = current.getCellPositon();
	for (Position item : tiles) {
		if (grid.isCellEmpty(item.r, item.c) == false)
			return false;
	}
	return true;
}


void Game::lockBlock() {
	std::vector<Position> tiles = current.getCellPositon();
	for (Position item : tiles) {
		grid.grid[item.r][item.c] = current.id;
	}
	current = next;
	if (blockFit() == false) {
		gameOver = true;
	}
	next = getRandomBlock();
}

void Game::reset() {
	gameOver = false;
	grid = Grid();
	blocks = getAllBlock();
	current = getRandomBlock();
	next = getRandomBlock();
}