#pragma once
#include "Gun.h"
#include "Vector_math.h"
#include <iostream>
using namespace std;

class Character : public Object {
private:
	Vector2 direction;
	float speed;
	Gun* gun;
	float width = 50;
	float height = 50;
public:

	Character(Vector2 pos, float speed);
	~Character();
	void move(float deltaTime);
	void input();
	void update(float deltaTime);
	void draw();
	Vector2 getPosition();
	Gun* getGun();
};