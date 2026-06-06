#pragma once
#include "raylib.h"

class Object {
protected:
	Vector2 position;
public:
	virtual ~Object() {}
	virtual void update(float deltaTime) = 0;
	virtual void draw() = 0;
};