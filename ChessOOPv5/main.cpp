#include "Game.cpp"

int main() {

	InitWindow(BLOCK_SIZE * SIZE, BLOCK_SIZE * SIZE, "My Chess");
	SetTargetFPS(24);
	Game chess;
	

	while (WindowShouldClose() == false) {
		chess.update();
		chess.draw();
	}
	
	CloseWindow();

	return 1;
}