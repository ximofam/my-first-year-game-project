#include <iostream>
#include "raylib.h"
#include <vector>
#define KING 1
#define KING1 -1
#define QUEEN 2
#define QUEEN1 -2
#define ROOK 3
#define ROOK1 -3
#define KNIGHT 4
#define KNIGHT1 -4
#define BISHOP 5
#define BISHOP1 -5
#define PAWN 6
#define PAWN1 -6
const int SIZE = 100;
using namespace std;
struct Position {
	int x, y;
	Position() {

	}
	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
bool isMouseInRectangle(int x, int y, int width, int height);
int board[8][8] = { 3, 4, 5 , 2 , 1,  5,  4 , 3,
					6,  6,  6,  6 , 6,  6,  6,  6,
					0,  0,  0,  0,  0,  0,  0,  0,
					0,  0,  0,  0,  0,  0 , 0,  0,
					0,  0,  0,  0,  0,  0,  0,  0,
					0,  0,  0 , 0,  0,  0,  0,  0,
					-6, -6, -6, -6, -6, -6, -6, -6,
					-3, -4, -5, -2, -1, -5, -4, -3
};

//int board[8][8] = { 0 };
class Figure {
public:
	bool isWhite;
	Position pos;
	int id;
	Texture2D image;
	Figure(int x, int y, int id, const char* source,bool white) {
		this->id = id;
		image = LoadTexture(source);
		image.width = SIZE;
		image.height = SIZE;
		pos.x = x;
		pos.y = y;
		isWhite = white;
	}
	void move(int r, int c) {
		pos.x = c * SIZE;
		pos.y = r * SIZE;
	}
	void draw() {
		DrawTexture(image, pos.x, pos.y, WHITE);
	}
};

vector<Figure> player1;
vector<Figure> player2;
Figure* selectedPiece = NULL;
vector<Position> PositionCanMove;
void drawChessBoardInConsole() {
	cout << "===========================================================\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << board[i][j] << "\t";
		}
		cout << endl;
		cout << endl;
	}
	cout << "===========================================================\n";
}
void drawChessBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
				DrawRectangle(j * SIZE, i * SIZE, SIZE, SIZE, RAYWHITE);
			}
			else {
				DrawRectangle(j * SIZE, i * SIZE, SIZE, SIZE, DARKBROWN);
			}
		}
	}
}
void deleteFigure(vector<Figure>& pieces, int x, int y) {
	for (int i = 0; i < pieces.size(); i++) {
		if (pieces[i].pos.x == x && pieces[i].pos.y == y) {
			pieces.erase(pieces.begin() + i);
		}
	}
}
vector<Position> GetPositionCanMove(Figure fg) {
	int piece = fg.id;
	const int r = fg.pos.y/SIZE;
	const int c = fg.pos.x/SIZE;
	int newR, newC;
	int I, J;
	int dr[] = { -1,-1,1,1,2,2,-2,-2 };
	int dc[] = { -2,2,-2,2,-1,1,-1,1 };

	if (piece < 0) piece = -piece;
	vector<Position> posCanMove;

	switch (piece)
	{
	case KING:
		for (int i = -1; i <= 1; i++) {
			newR = i + r;
			for (int j = -1; j <= 1; j++) {
				if (i != 0 || j != 0) {
					newC = j + c;
					if (newR >= 0 && newR < 8 && newC >= 0 && newC < 8) {
						if (board[newR][newC] == 0 || (board[r][c] > 0 && board[newR][newC] < 0) || (board[r][c] < 0 && board[newR][newC] > 0)) {
							posCanMove.push_back({ newC * SIZE,newR * SIZE });
						}
					}
				}
			}
		}
		break;
	case QUEEN:
		//di ngang
		for (int j = c+1; j < 8; j++) {
			if (board[r][j] == 0) {
				posCanMove.push_back({ j * SIZE,r * SIZE });
			}
			else if ((board[r][c] > 0 && board[r][j] < 0) || (board[r][c] < 0 && board[r][j] > 0)) {
				posCanMove.push_back({ j * SIZE,r * SIZE });
				break;
			}
			else break;
		}
		for (int j = c-1; j >= 0; j--) {
			if (board[r][j] == 0) {
				posCanMove.push_back({ j * SIZE,r * SIZE });
			}
			else if ((board[r][c] > 0 && board[r][j] < 0) || (board[r][c] < 0 && board[r][j] > 0)) {
				posCanMove.push_back({ j * SIZE,r * SIZE });
				break;
			}
			else break;
		}
		//di thang
		for (int i = r+1; i < 8; i++) {
			if (board[i][c] == 0) {
				posCanMove.push_back({ c * SIZE,i * SIZE });
			}
			else if ((board[r][c] > 0 && board[i][c] < 0) || (board[r][c] < 0 && board[i][c] > 0)) {
				posCanMove.push_back({ c * SIZE,i * SIZE });
				break;
			}
			else break;
		}
		for (int i = r-1; i >=0 ; i--) {
			if (board[i][c] == 0) {
				posCanMove.push_back({ c * SIZE,i * SIZE });
			}
			else if ((board[r][c] > 0 && board[i][c] < 0) || (board[r][c] < 0 && board[i][c] > 0)) {
				posCanMove.push_back({ c * SIZE,i * SIZE });
				break;
			}
			else break;
		}

		//di xeo
		I = r; J = c;
		while (I >= 0 && I < 8 && J >= 0 && J < 8) {
			if (I != r && J != c) {
				if (board[I][J] == 0) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
				}
				else if ((board[r][c] > 0 && board[I][J] < 0) || (board[r][c] < 0 && board[I][J] > 0)) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
					break;
				}
				else break;
			}
			I--;
			J++;
		}
		I = r; J = c;
		while (I >= 0 && I < 8 && J >= 0 && J < 8) {
			if (I != r && J != c) {
				if (board[I][J] == 0) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
				}
				else if ((board[r][c] > 0 && board[I][J] < 0) || (board[r][c] < 0 && board[I][J] > 0)) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
					break;
				}
				else break;
			}
			I++;
			J--;
		}
		I = r; J = c;
		while (I >= 0 && I < 8 && J >= 0 && J < 8) {
			if (I != r && J != c) {
				if (board[I][J] == 0) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
				}
				else if ((board[r][c] > 0 && board[I][J] < 0) || (board[r][c] < 0 && board[I][J] > 0)) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
					break;
				}
				else break;
			}
			I++;
			J++;
		}
		I = r; J = c;
		while (I >= 0 && I < 8 && J >= 0 && J < 8) {
			if (I != r && J != c) {
				if (board[I][J] == 0) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
				}
				else if ((board[r][c] > 0 && board[I][J] < 0) || (board[r][c] < 0 && board[I][J] > 0)) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
					break;
				}
				else break;
			}
			I--;
			J--;
		}
		break;
	case ROOK:
		//di ngang
		for (int j = c + 1; j < 8; j++) {
			if (board[r][j] == 0) {
				posCanMove.push_back({ j * SIZE,r * SIZE });
			}
			else if ((board[r][c] > 0 && board[r][j] < 0) || (board[r][c] < 0 && board[r][j] > 0)) {
				posCanMove.push_back({ j * SIZE,r * SIZE });
				break;
			}
			else break;
		}
		for (int j = c - 1; j >= 0; j--) {
			if (board[r][j] == 0) {
				posCanMove.push_back({ j * SIZE,r * SIZE });
			}
			else if ((board[r][c] > 0 && board[r][j] < 0) || (board[r][c] < 0 && board[r][j] > 0)) {
				posCanMove.push_back({ j * SIZE,r * SIZE });
				break;
			}
			else break;
		}
		//di thang
		for (int i = r + 1; i < 8; i++) {
			if (board[i][c] == 0) {
				posCanMove.push_back({ c * SIZE,i * SIZE });
			}
			else if ((board[r][c] > 0 && board[i][c] < 0) || (board[r][c] < 0 && board[i][c] > 0)) {
				posCanMove.push_back({ c * SIZE,i * SIZE });
				break;
			}
			else break;
		}
		for (int i = r - 1; i >= 0; i--) {
			if (board[i][c] == 0) {
				posCanMove.push_back({ c * SIZE,i * SIZE });
			}
			else if ((board[r][c] > 0 && board[i][c] < 0) || (board[r][c] < 0 && board[i][c] > 0)) {
				posCanMove.push_back({ c * SIZE,i * SIZE });
				break;
			}
			else break;
		}

		break;
	case KNIGHT:
		for (int i = 0; i < 8; i++) {
			newR = r + dr[i];
			newC = c + dc[i];
			if (newR >= 0 && newR < 8 && newC >= 0 && newC < 8) {
				if (board[newR][newC] == 0 || (board[r][c] > 0 && board[newR][newC] < 0) || (board[r][c] < 0 && board[newR][newC] > 0))
					posCanMove.push_back({ newC * SIZE,newR * SIZE });
			}
		}

		break;
	case BISHOP:
		I = r; J = c;
		while (I >= 0 && I < 8 && J >= 0 && J < 8) {
			if (I != r && J != c) {
				if (board[I][J] == 0) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
				}
				else if ((board[r][c] > 0 && board[I][J] < 0) || (board[r][c] < 0 && board[I][J] > 0)) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
					break;
				}
				else break;
			}
			I--;
			J++;
		}
		I = r; J = c;
		while (I >= 0 && I < 8 && J >= 0 && J < 8) {
			if (I != r && J != c) {
				if (board[I][J] == 0) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
				}
				else if ((board[r][c] > 0 && board[I][J] < 0) || (board[r][c] < 0 && board[I][J] > 0)) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
					break;
				}
				else break;
			}
			I++;
			J--;
		}
		I = r; J = c;
		while (I >= 0 && I < 8 && J >= 0 && J < 8) {
			if (I != r && J != c) {
				if (board[I][J] == 0) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
				}
				else if ((board[r][c] > 0 && board[I][J] < 0) || (board[r][c] < 0 && board[I][J] > 0)) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
					break;
				}
				else break;
			}
			I++;
			J++;
		}
		I = r; J = c;
		while (I >= 0 && I < 8 && J >= 0 && J < 8) {
			if (I != r && J != c) {
				if (board[I][J] == 0) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
				}
				else if ((board[r][c] > 0 && board[I][J] < 0) || (board[r][c] < 0 && board[I][J] > 0)) {
					posCanMove.push_back({ J * SIZE,I * SIZE });
					break;
				}
				else break;
			}
			I--;
			J--;
		}
		break;
	case PAWN:
		if (fg.id > 0) {
			if (board[r + 1][c] == 0) {
				posCanMove.push_back({ c * SIZE,(r + 1) * SIZE });
				if (r == 1 && board[r+2][c]==0) {
					posCanMove.push_back({ c * SIZE,(r + 2) * SIZE });
				}
			}
			if (board[r+1][c-1] < 0) {
				posCanMove.push_back({ (c - 1) * SIZE,(r+1)*SIZE });
			}
			if (board[r+1][c + 1] < 0) {
				posCanMove.push_back({ (c + 1) * SIZE,(r+1) * SIZE });
			}
		}
		else {
			if (board[r - 1][c] == 0) {
				posCanMove.push_back({ c * SIZE,(r - 1) * SIZE });
				if (r == 6 &&board[r-2][c]==0) {
					posCanMove.push_back({ c * SIZE,(r - 2) * SIZE });
				}
			}
			if (board[r-1][c - 1] > 0) {
				posCanMove.push_back({ (c - 1) * SIZE,(r-1)*SIZE });
			}
			if (board[r-1][c + 1] > 0) {
				posCanMove.push_back({ (c + 1) * SIZE,(r-1)*SIZE });
			}
		}
		break;
	default:
		break;
	}
	return posCanMove;
}


void init() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] > 0) {
				if (board[i][j] == KING) {
					player2.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\king.png",true));
				}
				else if (board[i][j] == QUEEN) {
					player2.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\queen.png",true));
				}
				else if (board[i][j] == ROOK) {
					player2.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\rook.png",true));
				}
				else if (board[i][j] == KNIGHT) {
					player2.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\knight.png",true));
				}
				else if (board[i][j] == BISHOP) {
					player2.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\bishop.png",true));
				}
				else if (board[i][j] == PAWN) {
					player2.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\pawn.png",true));
				}
			}
			else if (board[i][j] < 0) {
				if (board[i][j] == KING1) {
					player1.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\king1.png",false));
				}
				else if (board[i][j] == QUEEN1) {
					player1.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\queen1.png",false));
				}
				else if (board[i][j] == ROOK1) {
					player1.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\rook1.png",false));
				}
				else if (board[i][j] == KNIGHT1) {
					player1.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\knight1.png",false));
				}
				else if (board[i][j] == BISHOP1) {
					player1.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\bishop1.png",false));
				}
				else if (board[i][j] == PAWN1) {
					player1.push_back(Figure(j * SIZE, i * SIZE, board[i][j], "Resource\\pawn1.png",false));
				}
			}
		}
	}

}

void update() {
	if (selectedPiece==NULL&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		for (auto& piece : player1) {
			if (isMouseInRectangle(piece.pos.x, piece.pos.y, SIZE, SIZE)) {
				selectedPiece = &piece;
				PositionCanMove = GetPositionCanMove(piece);
				return;
			}
		}
		for (auto& piece : player2) {
			if (isMouseInRectangle(piece.pos.x, piece.pos.y, SIZE, SIZE)) {
				selectedPiece = &piece;
				PositionCanMove = GetPositionCanMove(piece);
				return;
			}
		}
	}
	else if (selectedPiece != NULL && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();
		Position *newPos = NULL;
		for (auto &pos : PositionCanMove) {
			if (int(mousePos.x / SIZE) == pos.x/SIZE && int(mousePos.y / SIZE) == pos.y/SIZE) {
				newPos = &pos;
				break;
			}
		}
		if (newPos != NULL) {
			board[selectedPiece->pos.y / SIZE][selectedPiece->pos.x / SIZE] = 0;
			if (board[newPos->y / SIZE][newPos->x / SIZE] > 0) {
				deleteFigure(player2, newPos->x, newPos->y);
			}
			else if (board[newPos->y / SIZE][newPos->x / SIZE] < 0) {
				deleteFigure(player1, newPos->x, newPos->y);
			}
			board[newPos->y / SIZE][newPos->x / SIZE] = selectedPiece->id;
			selectedPiece->pos = *newPos;

			if (selectedPiece->id == PAWN && selectedPiece->pos.y / SIZE == 7) {
				selectedPiece->id = QUEEN;
				UnloadTexture(selectedPiece->image);
				selectedPiece->image = LoadTexture("Resource\\queen.png");
				selectedPiece->image.width = SIZE;
				selectedPiece->image.height = SIZE;
			}
			else if (selectedPiece->id == PAWN1 && selectedPiece->pos.y / SIZE == 0) {
				selectedPiece->id = QUEEN1;
				UnloadTexture(selectedPiece->image);
				selectedPiece->image = LoadTexture("Resource\\queen1.png");
				selectedPiece->image.width = SIZE;
				selectedPiece->image.height = SIZE;
			}
		}



		selectedPiece = NULL;
		drawChessBoardInConsole();
	}


}
void render() {
	BeginDrawing();

	drawChessBoard();
	for (auto piece : player1) {
		piece.draw();
	}
	for (auto piece : player2) {
		piece.draw();
	}

	if (selectedPiece != NULL) {
		for (auto pos : PositionCanMove) {
			DrawCircle(pos.x + SIZE / 2, pos.y + SIZE / 2, 10, RED);
		}
	}
	//DrawFPS(0, 0);
	EndDrawing();
}

void quit() {
	for (auto &piece : player1) {
		UnloadTexture(piece.image);
	}
	for (auto &piece : player2) {
		UnloadTexture(piece.image);
	}
}

int main() {

	InitWindow(8*SIZE, 8*SIZE, "Chess Game");
	SetTargetFPS(30);

	init();
	
	while (WindowShouldClose() == false) {	
		update();
		render();
	}
	quit();
	CloseWindow();
	return 1;
}




bool isMouseInRectangle(int x,int y,int width,int height) {
	Vector2 mousePos = GetMousePosition();

	if (mousePos.x > x && mousePos.x<x + width && mousePos.y>y && mousePos.y < y + height) {
		return true;
	}
	return false;
}