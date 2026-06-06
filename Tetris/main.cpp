#include "Game.cpp"

int seconds = 0;
int minutes = 0;
Timer time(1);


int main() {
	InitWindow(SWIDTH, SHEIGHT, "Tetris");
	SetTargetFPS(FPS);
	
	Game game;

	while (WindowShouldClose() == false) {
		ClearBackground(BG_COLOR);
		
		game.update(GetFrameTime());
		if (time.isTime()) {
			seconds++;
			if (seconds == 60) {
				seconds = 0;
				minutes++;
			}
			time.turnOn();
		}
		else {
			time.update(GetFrameTime());
		}
		


		
		BeginDrawing();
		DrawText(TextFormat("%02d : %02d", minutes, seconds), SWIDTH - BLOCK_SIZE * 4, SHEIGHT / 2, BLOCK_SIZE, BLACK);
		game.draw();
		EndDrawing();
	}

	CloseWindow();
	return 1;
}