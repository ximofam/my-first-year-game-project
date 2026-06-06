#include "Board.cpp"
#include "DelayTime.cpp"


class Game {
private:
	Board board;
	std::vector<Block*> blocks;
	Block *selectedBlock;
	DelayTime moveDown = DelayTime(200);
	DelayTime inputTime = DelayTime(75);
	DelayTime rotateTime = DelayTime(125);
	bool canRotate = true;
	bool canInput = true;
	void shuffleArray(std::vector<Block*>& arr) {
		srand(time(0));  // Khởi tạo random seed

		int n = arr.size();
		for (int i = n - 1; i > 0; i--) {
			int j = rand() % (i + 1);
			std::swap(arr[i], arr[j]);
		}
	}
	std::vector<Block*> resetBlocks() {
		std::vector<Block*> newBlocks = { new BlockI(), new BlockO(), new BlockT(), new BlockL(), new BlockJ(), new BlockS(), new BlockZ() };
		shuffleArray(newBlocks);
		return newBlocks;
	}
	void createMap() {
		Config::gotoxy(Config::x - 1, Config::y - 1);
		std::cout << "+";
		for (int i = 0; i < 10; i++) std::cout << "-";
		std::cout << "+";

		for (int i = 0; i < 20; i++) {
			Config::gotoxy(Config::x - 1, Config::y + i);
			std::cout << "|";
		}


		Config::gotoxy(Config::x - 1, Config::y + 20);
		std::cout << "+";
		for (int i = 0; i < 10; i++) std::cout << "-";
		std::cout << "+";

		for (int i = 0; i < 20; i++) {
			Config::gotoxy(Config::x + 10, Config::y + i);
			std::cout << "|";
		}
	}
	void selectNewBlock() {
		if (selectedBlock != NULL)
			delete selectedBlock;
		selectedBlock = nextBlock();
	}
public:
	Game() {
		createMap();
		blocks = resetBlocks();
		selectedBlock = nextBlock();
	}
	~Game() {
		for (auto& block : blocks) {
			delete block;
		}
		delete selectedBlock;
	}

	Block* nextBlock() {
		if (blocks.empty()) {
			blocks = resetBlocks();
		}

		Block* block = blocks[blocks.size() - 1];
		blocks.pop_back();
		return block;
	}


	void input() {
		if (canInput && GetAsyncKeyState('A')) {
			canInput = false;
			selectedBlock->moveLeft();
			if (checkCollision()) selectedBlock->moveRight();
		}
		else if (canInput && GetAsyncKeyState('D')) {
			canInput = false;
			selectedBlock->moveRight();
			if (checkCollision()) selectedBlock->moveLeft();
		}
		else if (canInput && GetAsyncKeyState('S')) {
			canInput = false;
			selectedBlock->moveDown();
			if (checkCollision()) {
				selectedBlock->moveUp();
				board.setGrid(selectedBlock->getPositions());
				selectNewBlock();
			}
		}

		if (canRotate && GetAsyncKeyState('J')) {
			canRotate = false;
			selectedBlock->rotate();
			if (checkCollision()) selectedBlock->undoRotate();
		}



	}


	bool checkCollision() {
		std::vector<Position> positions = selectedBlock->getPositions();
		for (auto& pos : positions) {
			if (pos.x < Config::x || pos.x >= Config::x + board.col ||
				pos.y >= Config::y + board.row) return true;

			int r = pos.y - Config::y;
			int c = pos.x - Config::x;
			if (board.getGrid(r, c)) return true;
		}
		return false;
	}

	void update() {
		selectedBlock->erase();
		input();

		if (moveDown.update(Config::deltaTime)) {
			selectedBlock->moveDown();
			if (checkCollision()) {
				selectedBlock->moveUp();
				board.setGrid(selectedBlock->getPositions());
				selectNewBlock();
			}
		}

		if (inputTime.update(Config::deltaTime)) {
			canInput = true;
		}

		if (rotateTime.update(Config::deltaTime)) {
			canRotate = true;
		}

	}
	void draw() {
		board.draw();
		selectedBlock->draw();
	}
};