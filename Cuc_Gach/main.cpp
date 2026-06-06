#include "game.h"
#define WIDTH 300
#define HEIGHT 600

double lastUpdateTime = 0;
bool eventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main() {
	InitWindow(WIDTH, HEIGHT, "Tetris");
	SetTargetFPS(60);
	Game game;
	
	while (WindowShouldClose() == false) {
		game.handleInput();
		if (eventTriggered(0.2)) {
			game.moveDown();
		}
		game.draw();
	}
	CloseWindow();
	return 1;
}