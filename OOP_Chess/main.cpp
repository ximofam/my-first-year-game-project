#include "Game.h"


int main() {
	InitWindow(800, 800, "Chess");
	SetTargetFPS(30);
	Game Chess;
	while (WindowShouldClose() == false) {
		Chess.update();
		Chess.render();
	}
	CloseWindow();
}