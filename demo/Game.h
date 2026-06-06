#pragma once
#include "Character.h"
#define SCREEN_HEIGHT 600
class Game {
private:
	Character knight = Character({ 400,0 }, 100, 100);
	bool isOnFloor(Character* character) {
		if (character->position.y + character->height >= SCREEN_HEIGHT) {
			character->position.y = SCREEN_HEIGHT - character->height;
			return true;
		}
		return false;
	}
public:
	Game() {

	}
	void input() {
		knight.isRunning = false;
		if (IsKeyDown(KEY_A)) {
			knight.moveLeft(200.0f);
			if(knight.isJumping==false) knight.changeState(RUN);
		}
		else if (IsKeyDown(KEY_D)) {
			knight.moveRight(200.0f);
			if (knight.isJumping == false) knight.changeState(RUN);
		}
		else {
			knight.v.x = 0;
			if (knight.isJumping == false) knight.changeState(IDLE);
		}

		if (IsKeyDown(KEY_SPACE)) {
			knight.jump(-300.0f);
		}


		
	}
	void update() {
		if (knight.isJumping==true) {
			knight.changeState(ROLL);
		}
		knight.update(isOnFloor(&knight), 60);
		

		


	}

	void render() {
		BeginDrawing();
		ClearBackground(GRAY);
		DrawFPS(10, 10);
		knight.draw();
		EndDrawing();
	}
};
