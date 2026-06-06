#include "Enemy.cpp"



int main() {

	InitWindow(1000, 800, "Demo");
	SetTargetFPS(60);
	Figure figure({ 300,300 }, 300);
	Enemy *enemy = new Enemy({ 0.0f,0.0f }, 100);
	while (WindowShouldClose() == false) {
		ClearBackground(GRAY);
		if (enemy->getLife() > 0)
			enemy->moveTo(&figure);
		
		figure.update(GetFrameTime());
		if (enemy->getLife() > 0)
			enemy->update(GetFrameTime());
		
		figure.checkGunHitTo(enemy);
		

		BeginDrawing();
		figure.draw();
		if (enemy->getLife() > 0)
			enemy->draw();

		DrawGrid(30, 3);
		EndDrawing();

	}
	CloseWindow();

	return 1;
}