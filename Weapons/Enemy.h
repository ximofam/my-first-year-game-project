#pragma once
#include "Object.h"

class Enemy : public Object {
private:
	Vector2 direction = { 0, 0 };
	float speed;
	float width = 35;
	float height = 35;
public:
	Enemy(Vector2 position, float speed);
	~Enemy();
	void update(float deltaTime);
	void draw();
	void setDirection(Vector2 direction);
	Vector2 getPosition();
};
