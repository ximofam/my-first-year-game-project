#include "Config.cpp"
#include "string"

struct Position {
	int x, y;
	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Block {
protected:
	int x, y;
	int state;
	std::vector<std::vector<Position>> cells;

public:
	Block() {
		x = Config::x + 4;
		y = Config::y;
		state = 0;
	}
	~Block() {
		erase();
	}

	void moveLeft() {
		x--;
	}
	void moveRight() {
		x++;
	}
	void moveDown() {
		y++;
	}
	void moveUp() {
		y--;
	}

	void move() {
		if (GetAsyncKeyState('A')) {
			x--;
		}
		else if (GetAsyncKeyState('D')) {
			x++;
		}
		else if (GetAsyncKeyState('S')) {
			y++;
		}

		if (GetAsyncKeyState('J')) {
			rotate();
		}
	}



	void update() {
		erase();
	}

	void erase() {
		for (const auto& pos : cells[state]) {
			Config::gotoxy(x + pos.x, y + pos.y);
			std::cout << " ";
		}
	}

	void draw() {
		for (const auto& pos : cells[state]) {
			Config::gotoxy(x + pos.x, y + pos.y);
			std::cout << "#";
		}
	}
	void rotate() {
		state = (state + 1) % 4;
	}
	void undoRotate() {
		state = (state + 3) % 4;
	}
	std::vector<Position> getPositions(){
		std::vector<Position> positions = cells[state];
		for (auto& pos : positions) {
			pos.x += x;
			pos.y += y;
		}
		return positions;
	}
};