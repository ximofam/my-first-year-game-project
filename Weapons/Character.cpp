#include "Character.h"


Character::Character(Vector2 pos, float sp) {
	position = pos;
	speed = sp;
	direction = { 0, 0 };
	gun = new Gun();
	gun->setPosition(position);
}

Character::~Character() {
	delete gun;

	cout << "Da giai phong character\n";
}

void Character::input() {

	direction = { 0, 0 };

	if (IsKeyDown(KEY_A)) {
		direction.x = -1;
	}
	else if (IsKeyDown(KEY_D)) {
		direction.x = 1;
	}
	if (IsKeyDown(KEY_W)) {
		direction.y = -1;
	}
	else if (IsKeyDown(KEY_S)) {
		direction.y = 1;
	}


}

void Character::move(float deltaTime) {
	if (direction.x != 0 && direction.y != 0) {
		direction = NormalizeVector(direction);
	}

	position.x += direction.x * speed * deltaTime;
	position.y += direction.y * speed * deltaTime;
}

void Character::update(float deltaTime) {
	input();

	if (direction.x != 0 || direction.y != 0) move(deltaTime);

	gun->setPosition(position);
	gun->update(deltaTime);
}

void Character::draw() {
	gun->draw();

	DrawRectanglePro({ position.x, position.y, width, height }, { width / 2, height / 2 }, 0, RED);
}

Vector2 Character::getPosition() {
	return position;
}

Gun* Character::getGun() {
	return gun;
}