#include "Board.h"
#include <vector>
using namespace std;

class Logic {
private:
	static vector<Position> posCanMoveOfKing(Board* board, Piece* piece) {
		vector<Position> positions;
		Position pos = piece->getPosition();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				Position newPos = { pos.row + i, pos.col + j };
				if (board->isValidMove(piece, newPos))
					positions.push_back(newPos);
			}
		}
		return positions;
	}
	static vector<Position> posCanMoveOfRook(Board* board, Piece* piece) {
		vector<Position> positions;
		pair<int, int> directions[] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
		for (auto& dir : directions) {
			Position newPos = piece->getPosition();
			int dr = dir.first;
			int dc = dir.second;
			while (1) {
				newPos = { newPos.row + dr, newPos.col + dc };
				if (board->isValidMove(piece, newPos) != 0) {
					positions.push_back(newPos);
					if (board->isValidMove(piece, newPos) == -1) break;
				}
				else break;
			}
		}
		return positions;
	}
	static vector<Position> posCanMoveOfBishop(Board* board, Piece* piece) {
		vector<Position> positions;
		pair<int, int> directions[] = { {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
		for (auto& dir : directions) {
			Position newPos = piece->getPosition();
			int dr = dir.first;
			int dc = dir.second;
			while (1) {
				newPos = { newPos.row + dr, newPos.col + dc };
				if (board->isValidMove(piece, newPos) != 0) {
					positions.push_back(newPos);
					if (board->isValidMove(piece, newPos) == -1) break;
				}
				else break;
			}
		}
		return positions;
	}
	static vector<Position> posCanMoveOfQueen(Board* board, Piece* piece) {
		vector<Position> result;
		for (auto& pos : posCanMoveOfRook(board, piece)) {
			result.push_back(pos);
		}
		for (auto& pos : posCanMoveOfBishop(board, piece)) {
			result.push_back(pos);
		}
		return result;
	}
	static vector<Position> posCanMoveOfKnight(Board* board, Piece* piece) {
		vector<Position> result;
		pair<int, int> directions[] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
		Position pos = piece->getPosition();
		for (auto& dir : directions) {
			Position newPos = { pos.row + dir.first, pos.col + dir.second };
			if (board->isValidMove(piece, newPos))
				result.push_back(newPos);
		}
		return result;
	}

public:
	static vector<Position> getPosCanMove(Board* board, Piece* piece) {

		switch (piece->getType()) {
		case 'K': return posCanMoveOfKing(board, piece);
		case 'Q': return posCanMoveOfQueen(board, piece);
		case 'R': return posCanMoveOfRook(board, piece);
		case 'N': return posCanMoveOfKnight(board, piece);
		case 'B': return posCanMoveOfBishop(board, piece);
		}

		return vector<Position>();
	}
};