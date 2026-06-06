#include <iostream>
#include <vector>
#include "Pieces.cpp"

class Board {
private:
	int size;
	vector<vector<Piece*>> board;
public:
	Board(int size) {
		this->size = size;
		board.assign(size, vector<Piece*>(size, nullptr));
	}
	~Board() {
		for (auto& row : board) {
			for (auto& piece : row) {
				if (piece != nullptr) {
					delete piece;
				}
			}
		}
		cout << "Da giai phong vung nho";
	}

	int canMove(int row, int col, int rowDes, int colDes) {
		if (rowDes < 0 || rowDes >= size || colDes < 0 || colDes >= size)
			return 0;
		if (board[row][col]->canMoveTo(rowDes, colDes)) {
			if (board[rowDes][colDes] == nullptr)
				return 1;
			if (board[row][col]->getColor() != board[rowDes][colDes]->getColor())
				return -1;
		}
		return 0;
	}

	void placePiece(Piece* piece, int row, int col) {
		if (piece == nullptr) return;

		piece->setPosition(row, col);
		if (board[row][col] != nullptr) delete board[row][col];
		board[row][col] = piece;
	}

	void movePiece(int row, int col, int rowDes, int colDes) {
		placePiece(board[row][col], rowDes, colDes);
		board[row][col] = nullptr;
	}

	void draw() {
		char c = 'a';
		cout << "  ";
		for (int i = 0; i < size; i++) {
			cout << "  " << c++ << "  ";
		}
		cout << "\n\n";
		int rank = size;
		for (auto& row : board) {
			cout << rank << " ";
			for (auto& piece : row) {
				if (piece == nullptr)
					cout << "  .  ";
				else
					cout << piece->toString();
			}
			cout << " " << rank-- << "\n\n";
		}
		c = 'a';
		cout << "  ";
		for (int i = 0; i < size; i++) {
			cout << "  " << c++ << "  ";
		}
		cout << endl;
	}

	Piece* getPiece(int row, int col) {
		return board[row][col];
	}
	int getSize() {
		return size;
	}
};