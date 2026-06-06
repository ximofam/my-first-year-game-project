#include "Piece.cpp"
#define ABS(x) ((x) < 0 ? -(x) : (x))


class King : public Piece {
public:

	King(Color color) {
		this->color = color;
	}

	string getSymbol() override {
		return color == WHITE ? "K" : "k";
	}
	
	bool canMoveTo(int row, int col) override {
		if (this->row == row && this->col == col) return false;
		int rowDiff = ABS(this->row - row);
		int colDiff = ABS(this->col - col);
		return rowDiff <= 1 && colDiff <= 1;
	}
};

class Queen : public Piece {
public:
	Queen(Color color) {
		this->color = color;
	}

	string getSymbol() override {
		return color == WHITE ? "Q" : "q";
	}

	bool canMoveTo(int row, int col) override {
		if (this->row == row && this->col == col) return false;
		int rowDiff = ABS(this->row - row);
		int colDiff = ABS(this->col - col);
		return rowDiff == 0 || colDiff == 0 || rowDiff == colDiff;
	}
};

class Rook : public Piece {
public:
	Rook(Color color) {
		this->color = color;
	}

	string getSymbol() override {
		return color == WHITE ? "R" : "r";
	}
	
	bool canMoveTo(int row, int col) override {
		if (this->row == row && this->col == col) return false;
		int rowDiff = ABS(this->row - row);
		int colDiff = ABS(this->col - col);
		return rowDiff == 0 || colDiff == 0;
	}
};

class Knight : public Piece {
public:
	Knight(Color color) {
		this->color = color;
	}

	string getSymbol() override {
		return color == WHITE ? "N" : "n";
	}
	
	bool canMoveTo(int row, int col) override {
		if (this->row == row && this->col == col) return false;
		int rowDiff = ABS(this->row - row);
		int colDiff = ABS(this->col - col);
		return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
	}
};

class Bishop : public Piece {
public:
	Bishop(Color color) {
		this->color = color;
	}

	string getSymbol() override {
		return color == WHITE ? "B" : "b";
	}
	
	bool canMoveTo(int row, int col) override {
		if (this->row == row && this->col == col) return false;
		int rowDiff = ABS(this->row - row);
		int colDiff = ABS(this->col - col);
		return rowDiff == colDiff;
	}
};

class Pawn : public Piece {
public:
	Pawn(Color color) {
		this->color = color;
	}

	string getSymbol() override {
		return color == WHITE ? "P" : "p";
	}
	
	bool canMoveTo(int row, int col) override {
		if (this->row == row && this->col == col) return false;
		if (col != this->col) return false;

		if (color == WHITE) {
			if (row - this->row == -2 && this->row == 6) return true;
			return row - this->row == -1;
		}
		
		if (row - this->row == 2 && this->row == 1) return true;
		return row - this->row == 1;
	}
};