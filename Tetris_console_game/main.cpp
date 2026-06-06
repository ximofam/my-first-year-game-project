
#include "Game.cpp"


int main() {
	

	
	Game Tetris;
	
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		
		Tetris.update();
		Tetris.draw();

		Sleep(Config::deltaTime);
	}
	
	return 1;
}