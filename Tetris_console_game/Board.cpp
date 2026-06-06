#include <vector>
#include "Blocks.cpp"

class Board {
private:
	std::vector<std::vector<int>> grid;
public:
	int row;
	int col;
	Board() {
		row = 20;
		col = 10;
		grid.assign(row, std::vector<int>(col, 0));
		grid[0][0] = grid[19][9] = 1;
		grid[5][9] = 1;
	}

	bool checkRow(int i) {
		for (const auto& x : grid[i]) {
			if (x == 0) return false;
		}
		return true;
	}

	void shifDownRow(int i) {
		for (int r = i; r > 0; r--) {
			grid[r] = grid[r - 1];
		}
	}
	void update() {
		for (int i = 0; i < grid.size(); i++) {
			if (checkRow(i))
				shifDownRow(i);
		}
	}

	void draw() {
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j]) {
					Config::gotoxy(Config::x + j, Config::y + i);
					std::cout << "#";
				}
			}
		}
	}
	int getGrid(int r, int c) {
		return grid[r][c];
	}
	void setGrid(std::vector<Position> positions) {
		for (auto& pos : positions) {
			int r = pos.y - Config::y;
			int c = pos.x - Config::x;
			grid[r][c] = 1;
		}
	}
};