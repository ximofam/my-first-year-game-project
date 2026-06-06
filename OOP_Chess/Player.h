#pragma once
#include "Board.h"
#include <vector>
#include <utility>
class Player {
private:
	int color;
	std::vector<Piece*> pieces;
public:
	Player() {

	}
	Player(int color) {
		this->color = color;
	}
	void addPiece(Piece *piece) {
		pieces.push_back(piece);
	}
	void makeMove(Board& board, int r, int c, int desR, int desC) {
		board.move(r, c, desR, desC);
	}
	bool lose() {
		if (pieces.empty())
			return true;
		for (auto piece : pieces) {
			if (piece->getId() == KING) {
				return false;
			}
		}
		return true;
	}
	int getColor() {
		return color;
	}
	void deletePiece(int r, int c) {
		for (int i = 0; i < pieces.size(); i++) {
			std::pair<int, int> pos = pieces[i]->getPosition();
			if (pos.first == r && pos.second == c) {
				pieces.erase(pieces.begin() + i);
			}
		}
	}
};