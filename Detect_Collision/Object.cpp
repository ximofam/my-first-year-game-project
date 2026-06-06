#include "Vector2D.cpp"
#include "raylib.h"

class Object {
protected:
	Vector2D position;
	Vector2D direction;
	float speed;
public:
	Object() {
		direction = { 0,0 };
	}


	virtual void update(float deltaTime) {

	}
	virtual void draw() {

	}


	void setSpeed(float speed) {
		this->speed = speed;
	}
	void setPosition(Vector2D position) {
		this->position = position;
	}
	void setDirection(Vector2D direction) {
		this->direction = direction;
	}
	Vector2D getPosition() {
		return position;
	}
	Vector2D getDirection() {
		return direction;
	}
	float getSpeed() {
		return speed;
	}


};