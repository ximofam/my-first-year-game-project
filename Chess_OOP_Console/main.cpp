#include "Game.cpp"


int main() {
	Game* Chess = new Game();

	Chess->render();

	delete Chess;
	return 1;
}