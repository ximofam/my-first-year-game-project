#include "Game.h"

int main() {
	InitWindow(800, 800, "chess");
	SetTargetFPS(30);
	Game chess;
	while (WindowShouldClose() == false) {
		chess.update();
		chess.render();
	}
	CloseWindow();
	return 1;
}