#include "Game.cpp"



int main() {
	Game myGame;

	while (!GetAsyncKeyState(VK_ESCAPE)) {
		myGame.update();
		myGame.draw();
		Sleep(Config::deltaTime);
	}
	return 1;
}