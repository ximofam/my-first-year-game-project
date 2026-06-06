#include "Block.cpp"


class BlockI : public Block{
public:
	BlockI() {
		cells.push_back({ Position(0,0),Position(1,0),Position(2,0),Position(3,0) });
		cells.push_back({ Position(2,0),Position(2,1),Position(2,2),Position(2,3) });
		cells.push_back({ Position(0,2),Position(1,2),Position(2,2),Position(3,2) });
		cells.push_back({ Position(1,0),Position(1,1),Position(1,2),Position(1,3) });
	}
};

class BlockO : public Block {
public:
	BlockO() {
		cells.push_back({ Position(0,0), Position(1,0), Position(0,1), Position(1,1) });
		cells.push_back({ Position(1,0), Position(1,1), Position(2,0), Position(2,1) });
		cells.push_back({ Position(0,1), Position(1,1), Position(0,2), Position(1,2) });
		cells.push_back({ Position(1,0), Position(1,1), Position(2,0), Position(2,1) });
	}
};

class BlockT : public Block {
public:
	BlockT() {
		cells.push_back({ Position(0,1), Position(1,1), Position(2,1), Position(1,0) });
		cells.push_back({ Position(1,0), Position(1,1), Position(1,2), Position(0,1) });
		cells.push_back({ Position(0,1), Position(1,1), Position(2,1), Position(1,2) });
		cells.push_back({ Position(1,0), Position(1,1), Position(1,2), Position(2,1) });
	}
};

class BlockJ : public Block {
public:
	BlockJ() {
		cells.push_back({ Position(0,0), Position(1,0), Position(2,0), Position(2,1) });
		cells.push_back({ Position(1,0), Position(1,1), Position(1,2), Position(2,0) });
		cells.push_back({ Position(0,2), Position(1,2), Position(2,2), Position(2,1) });
		cells.push_back({ Position(0,1), Position(1,1), Position(2,1), Position(0,0) });
	}
};

class BlockL : public Block {
public:
	BlockL() {
		cells.push_back({ Position(0,1), Position(1,1), Position(2,1), Position(2,0) });
		cells.push_back({ Position(1,0), Position(1,1), Position(1,2), Position(0,2) });
		cells.push_back({ Position(0,0), Position(1,0), Position(2,0), Position(0,1) });
		cells.push_back({ Position(0,0), Position(0,1), Position(0,2), Position(1,2) });
	}
};
class BlockS : public Block {
public:
	BlockS() {
		cells.push_back({ Position(1,0), Position(2,0), Position(0,1), Position(1,1) });
		cells.push_back({ Position(1,0), Position(1,1), Position(2,1), Position(2,2) });
		cells.push_back({ Position(0,1), Position(1,1), Position(1,2), Position(2,2) });
		cells.push_back({ Position(1,0), Position(2,0), Position(2,1), Position(0,2) });
	}
};

class BlockZ : public Block {
public:
	BlockZ() {
		cells.push_back({ Position(0,0), Position(1,0), Position(1,1), Position(2,1) });
		cells.push_back({ Position(2,0), Position(1,0), Position(1,1), Position(0,1) });
		cells.push_back({ Position(0,1), Position(1,1), Position(1,2), Position(2,2) });
		cells.push_back({ Position(0,0), Position(1,0), Position(1,1), Position(2,1) });
	}
};