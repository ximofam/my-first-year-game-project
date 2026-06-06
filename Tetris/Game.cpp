#include "Grid.h"
#include "Timer.h"
#include <algorithm>

class Game {
private:


	Grid grid;
	vector<Block*> blocks;
	Block* selectedBlock = NULL;
	Block* nextBlock = NULL;
	Timer* dropTime;
	Timer* moveTime;


	void initBlocks() {
		blocks = {new BlockI(),new BlockJ(),new BlockL(),new BlockO(),new BlockS(),new BlockT(),new BlockZ() };
		random_shuffle(blocks.begin(), blocks.end());
	}

	Block* getNextBlock() {
		if (blocks.empty()) {
			initBlocks();
		}
		Block* res = blocks.back();
		blocks.pop_back();
		return res;
	}

	void updateSelectedBlock() {
		selectedBlock->moveDown();
		if (grid.isTouchBottom(selectedBlock)) {
			selectedBlock->moveUp();
			grid.setPosGrid(selectedBlock);
			delete selectedBlock;
			selectedBlock = NULL;

			checkCollide();
		}
	}
	void drawNextBlock() {
		vector<Position> positions = nextBlock->getMatrix();
		for (auto& pos : positions) {
			DrawRectangle(OFFSET_X + (MAX_COL + pos.col) * BLOCK_SIZE + 50, OFFSET_Y + pos.row * BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, nextBlock->getColor());
		}
	}

	vector<Position> getFutureBlock() {
		vector<Position> positions = selectedBlock->getPositions();
		int n = MAX_ROW;

		while (n--) {
			vector<Position> temp;
			for (auto& pos : positions) {
				temp.push_back({ pos.row + 1, pos.col });
			}

			if (grid.isTouchBottom(temp)) {
				return positions;
			}
			else {
				positions = temp;
			}
		}

		return vector<Position>();
	}

	void checkCollide() {
		for (int i = 0; i < MAX_ROW; i++) {
			if (grid.isFullRow(i)) {
				grid.shiftDownRow(i);
			}
		}
	}
	

public:
	Game() {
		dropTime = new Timer(0.75);
		moveTime = new Timer(0.15);
		initBlocks();
		nextBlock = getNextBlock();
	}
	~Game() {
		delete dropTime;
		delete moveTime;
		for (Block* block : blocks) {
			delete block;
		}
	}
	void update(float deltaTime) {
		if (selectedBlock == NULL) {
			selectedBlock = nextBlock;
			nextBlock = getNextBlock();
		}
		else {

			if (moveTime->isTime()) {

				if (IsKeyDown(KEY_LEFT)) {
					selectedBlock->moveLeft();
					if (grid.isValidMove(selectedBlock)) {
						moveTime->turnOn();
					}
					else {
						selectedBlock->moveRight();
					}
				}
				else if (IsKeyDown(KEY_RIGHT)) {
					selectedBlock->moveRight();
					if (grid.isValidMove(selectedBlock)) {
						moveTime->turnOn();
					}
					else {
						selectedBlock->moveLeft();
					}
				}
			}

			if (moveTime->isTime() && IsKeyDown(KEY_DOWN)) {
				updateSelectedBlock();
				moveTime->turnOn();
				dropTime->reset();
			}
			else if (dropTime->isTime()) {
				updateSelectedBlock();
				dropTime->turnOn();
			}

			if (IsKeyPressed(KEY_Z)) {
				selectedBlock->rotateLeft();
				if (grid.isValidMove(selectedBlock) == false) {
					selectedBlock->rotateRight();
				}
			}
			else if (IsKeyPressed(KEY_UP)) {
				selectedBlock->rotateRight();
				if (grid.isValidMove(selectedBlock) == false) {
					selectedBlock->rotateLeft();
				}
			}

			if (IsKeyPressed(KEY_SPACE)) {
				grid.setPosGrid(getFutureBlock(), selectedBlock->getSign());
				delete selectedBlock;
				selectedBlock = NULL;

				checkCollide();
			}


		}

		
		if (dropTime->isTime() == false) {
			dropTime->update(deltaTime);
		}

		if (moveTime->isTime() == false) {
			moveTime->update(deltaTime);
		}

	}
	void draw() {
		grid.draw();
		if (selectedBlock) {
			selectedBlock->draw();
			for (auto& pos : getFutureBlock()) {
				DrawRectangle(OFFSET_X + pos.col * BLOCK_SIZE, OFFSET_Y + pos.row * BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, DARKGRAY);
			}
		}
		if (nextBlock) {
			drawNextBlock();
		}

	}
};