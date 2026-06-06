#include "Blocks.h"

BlockI::BlockI() {
	offsetRow--;
	SIGN = 1;
	color = Block::COLORS[SIGN];
	cells.push_back({ {1,0},{1,1},{1,2},{1,3} });
	cells.push_back({ {0,2},{1,2},{2,2},{3,2} });
	cells.push_back({ {2,0},{2,1},{2,2},{2,3} });
	cells.push_back({ {0,1},{1,1},{2,1},{3,1} });
}

BlockJ::BlockJ() {
	SIGN = 2;
	color = Block::COLORS[SIGN];
	cells.push_back({ {0,0},{1,0},{1,1},{1,2} });
	cells.push_back({ {0,1},{0,2},{1,1},{2,1} });
	cells.push_back({ {1,0},{1,1},{1,2},{2,2} });
	cells.push_back({ {0,1},{1,1},{2,0},{2,1} });
}

BlockL::BlockL() {
	SIGN = 3;
	color = Block::COLORS[SIGN];
	cells.push_back({ {0,2},{1,0},{1,1},{1,2} });
	cells.push_back({ {0,1},{1,1},{2,1},{2,2} });
	cells.push_back({ {1,0},{1,1},{1,2},{2,0} });
	cells.push_back({ {0,0},{0,1},{1,1},{2,1} });
}

BlockO::BlockO() {
	SIGN = 4;
	color = Block::COLORS[SIGN];
	cells.push_back({ {0,0},{0,1},{1,0},{1,1} });
	cells.push_back({ {0,0},{0,1},{1,0},{1,1} });
	cells.push_back({ {0,0},{0,1},{1,0},{1,1} });
	cells.push_back({ {0,0},{0,1},{1,0},{1,1} });
}

BlockS::BlockS() {
	SIGN = 5;
	color = Block::COLORS[SIGN];
	cells.push_back({ {0,1},{0,2},{1,0},{1,1} });
	cells.push_back({ {0,1},{1,1},{1,2},{2,2} });
	cells.push_back({ {1,1},{1,2},{2,0},{2,1} });
	cells.push_back({ {0,0},{1,0},{1,1},{2,1} });
}

BlockT::BlockT() {
	SIGN = 6;
	color = Block::COLORS[SIGN];
	cells.push_back({ {0,1},{1,0},{1,1},{1,2} });
	cells.push_back({ {0,1},{1,1},{1,2},{2,1} });
	cells.push_back({ {1,0},{1,1},{1,2},{2,1} });
	cells.push_back({ {0,1},{1,0},{1,1},{2,1} });
}

BlockZ::BlockZ() {
	SIGN = 7;
	color = Block::COLORS[SIGN];
	cells.push_back({ {0,0},{0,1},{1,1},{1,2} });
	cells.push_back({ {0,2},{1,1},{1,2},{2,1} });
	cells.push_back({ {1,0},{1,1},{2,1},{2,2} });
	cells.push_back({ {0,1},{1,0},{1,1},{2,0} });
}