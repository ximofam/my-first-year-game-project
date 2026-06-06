#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
private:
	std::vector<Block> blocks;
	Block current;
	Block next;
public:
	bool gameOver;
	Grid grid;
	Game();
	std::vector<Block> getAllBlock();
	Block getRandomBlock();
	void draw();
	void update();
	void handleInput();
	void moveLeft();
	void moveRight();
	void moveDown();
	bool isBlockOutside();
	void rotateBlock();
	void lockBlock();
	bool blockFit();
	void reset();
};
