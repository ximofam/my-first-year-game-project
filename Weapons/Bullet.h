#pragma once
#include "Object.h"

class Bullet : public Object {
private:
	Vector2 direction;
	float existanceTime;
	float speed = 1000;
	bool active;
public:
	Bullet(Vector2 pos, Vector2 dir, float range);
	~Bullet();
	void update(float deltaTime);
	void draw();
	bool isActive();
	void deActive();
};