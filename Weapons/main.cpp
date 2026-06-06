#include "Game.cpp"


int main() {

	InitWindow(1200, 900, "Demo");
	SetTargetFPS(240);

	Game game;

	while (WindowShouldClose() == false) {
		
		ClearBackground(GRAY);
		DrawFPS(10, 10);
		float deltaTime = 1.0f / GetFPS();

		game.update(deltaTime);

		BeginDrawing();
		game.render();
		EndDrawing();
	}

	CloseWindow();


	return 0;
}