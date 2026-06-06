#include "Enemy.h"

Enemy::Enemy(Vector2 pos, float sp) {
	position = pos;
	speed = sp;
}

Enemy::~Enemy() {

}

void Enemy::update(float deltaTime) {
	position.x += direction.x * speed * deltaTime;
	position.y += direction.y * speed * deltaTime;
}

void Enemy::draw() {
	DrawRectanglePro({ position.x, position.y, width, height }, { width / 2, height / 2 }, 0, DARKBROWN);
}

void Enemy::setDirection(Vector2 dir) {
	direction = dir;
}

Vector2 Enemy::getPosition() {
	return position;
}