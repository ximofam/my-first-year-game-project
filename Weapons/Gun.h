#pragma once
#include "Bullet.h"
#include "DelayTime.h"
#include <vector>
#include <iostream>
using namespace std;

class Gun : public Object {
private:
	float range;
	int numberOfBullets;
	DelayTime* reloadTime;
	DelayTime* shootTime;
	vector<Bullet*> bullets;
	void resetState();
public:
	Gun();
	~Gun();
	void shoot(Vector2 direction);
	void reload();
	void update(float deltaTime);
	void draw();
	void setPosition(Vector2 pos);
	Vector2 getPosition();
	float getRange();
	bool isOutOfAmmo();
	vector<Bullet*> getBullets();
};