#include "Bullet.h"

Bullet::Bullet(Vector2 pos, Vector2 dir, float range) {
	position = pos;
	direction = dir;
	existanceTime = range / speed;  
	active = true;
}

Bullet::~Bullet() {

}

void Bullet::update(float deltaTime) {
	if (active) {
		existanceTime -= deltaTime;
		if (existanceTime < 0) active = false;

		position.x += direction.x * speed * deltaTime;
		position.y += direction.y * speed * deltaTime;
	}
}

void Bullet::draw() {
	if (active) {
		DrawCircleV(position, 10, BLACK);
	}
}

bool Bullet::isActive() {
	return active;
}

void Bullet::deActive() {
	active = false;
}