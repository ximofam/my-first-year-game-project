#include "Board.cpp"

class Logic {
public:
	static vector<pair<int, int>> generateKingMoves(Board* board, int row, int col) {
		vector<pair<int, int>> res;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int r = row + i;
				int c = col + j;
				if (board->canMove(row, col, r, c))
					res.push_back({ r, c });
			}
		}
		return res;
	}
	static vector<pair<int, int>> generateRookMoves(Board* board, int row, int col) {
		vector<pair<int, int>> res;
		int dr[] = { 0, 0, 1, -1 };
		int dc[] = { 1, -1, 0, 0 };

		for (int i = 0; i < 4; i++) {
			int r = row, c = col;
			while (true) {
				r += dr[i];
				c += dc[i];

				if (board->canMove(row, col, r, c) == 0) break;
				res.push_back({ r,c });
				if (board->canMove(row, col, r, c) == -1) break;
			}
		}
		return res;
	}

	static vector<pair<int, int>> generateBishopMoves(Board* board, int row, int col) {
		vector<pair<int, int>> res;
		int dr[] = { 1,-1,1,-1 };
		int dc[] = { 1,-1,-1,1 };

		for (int i = 0; i < 4; i++) {
			int r = row, c = col;
			while (true) {
				r += dr[i];
				c += dc[i];

				if (board->canMove(row, col, r, c) == 0) break;
				res.push_back({ r,c });
				if (board->canMove(row, col, r, c) == -1) break;
			}
		}
		return res;
	}

	static vector<pair<int, int>> generateQueenMoves(Board* board, int row, int col) {
		vector<pair<int, int>> res1 = generateRookMoves(board, row, col);
		vector<pair<int, int>> res2 = generateBishopMoves(board, row, col);
		for (auto& x : res2)
			res1.push_back(x);
		return res1;
	}
	static vector<pair<int, int>> generateKnightMoves(Board* board, int row, int col) {
		vector<pair<int, int>> res;
		int dr[] = { 1,1,-1,-1,2,2,-2,-2 };
		int dc[] = { 2,-2,2,-2,1,-1,1,-1 };
		for (int i = 0; i < 8; i++) {
			int r = row + dr[i];
			int c = col + dc[i];
			if (board->canMove(row, col, r, c) != 0) {
				res.push_back({ r, c });
			}
		}
		return res;
	}
	static vector<pair<int, int>> generatePawnMoves(Board* board, int row, int col) {
		vector<pair<int, int>> res;
		int dr[] = { 1, 1, 1, -1, -1, -1 };
		int dc[] = { 0, 1, -1, 1, -1, 0 };
		for (int i = 0; i < 6; i++) {
			int r = row + dr[i];
			int c = col + dc[i];
			if (board->canMove(row, col, r, col)) {
				if (c == col) {
					res.push_back({ r, c });
				}
				else if (board->getPiece(row,col)->getColor() != board->getPiece(r,c)->getColor()){
					res.push_back({ r,c });
				}
			}
		}
		if (board->canMove(row, col, row + 2, col)) res.push_back({ row + 2, col });
		if (board->canMove(row, col, row - 2, col)) res.push_back({ row - 2, col });
		return res;
	}

	static vector<pair<int, int>> generateMoves(Board* board, int row, int col) {
		char c = board->getPiece(row, col)->getSymbol()[0];
		switch (c) {
		case 'K': case 'k':
			return generateKingMoves(board, row, col);
		case 'Q': case 'q':
			return generateQueenMoves(board, row, col);
		case 'N': case 'n':
			return generateKnightMoves(board, row, col);
		case 'R': case 'r':
			return generateRookMoves(board, row, col);
		case 'B': case 'b':
			return generateBishopMoves(board, row, col);
		case 'P': case 'p':
			return generatePawnMoves(board, row, col);
		default:
			return vector<pair<int, int>>();
		}
	}
};