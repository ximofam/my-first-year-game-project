#include <string>
using namespace std;

enum Color {
	WHITE, BLACK
};

class Piece {
protected:
	int row, col;
	Color color;
public:
	

	string toString() {
		return " [" + getSymbol() + "] ";
	}
	virtual bool canMoveTo(int row, int col) = 0;
	virtual string getSymbol() = 0;

	void setPosition(int row, int col) {
		this->row = row;
		this->col = col;
	}
	Color getColor() {
		return color;
	}
	int getRow() {
		return row;
	}
	int getCol() {
		return col;
	}
};