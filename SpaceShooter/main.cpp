#include "raylib.h"

int main() {

	InitWindow(400, 800, "SpaceShooter");
	while (WindowShouldClose() == false) {
		BeginDrawing();

		EndDrawing();
	}


	CloseWindow();
	return 1;
}