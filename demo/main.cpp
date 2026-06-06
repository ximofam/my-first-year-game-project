#include "Game.h"




int main() {

	InitWindow(800, 600, "Demo");
	SetTargetFPS(60);
	
	Game game=Game();
	
	while (WindowShouldClose()==false) {
		game.input();
		game.update();
		game.render();
	}

	CloseWindow();

	return 1;
}