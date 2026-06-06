#include "Config.cpp"
#include <iostream>
#include "Object.cpp"

class Bullet : public Object{
private:
	bool isActive;
	int speed;
	int direction;
public:
	Bullet(int x, int y, int speed) {
		this->x = x;
		this->y = y;
		isActive = true;
		this->speed = speed;
		direction = 1;
	}
	Bullet(int x, int y, int speed, int direction) {
		this->x = x;
		this->y = y;
		isActive = true;
		this->speed = speed;
		this->direction = direction;
	}
	Bullet() {
		isActive = false;
	}

	bool checkCollision() override {
		if (direction == Config::DIRECTION_LEFT)
			return this->x <= 0;
		else
			return this->x >= Config::WIDTH;
	}

	bool checkCollision(Object *oj) override {
		if (oj->getClassName() == "Bullet") {
			if (direction == Config::DIRECTION_LEFT)
				return this->x <= oj->getX() && this->y == oj->getY();
			else if (direction == Config::DIRECTION_RIGHT)
				return this->x >= oj->getX() && this->y == oj->getY();
		}
		else if (oj->getClassName() == "SpaceShip") {
			return Config::checkCollision(x, y, oj->getX(), oj->getY(), oj->getWidth(), oj->getHeight());
		}
		return false;
	}

	std::string getClassName() override {
		return "Bullet";
	}

	void erase() {
		Config::gotoxy(x, y);
		std::cout << " ";
	}

	void move() override {
		if (isActive) {
			erase();
			x += speed * direction;
		}
	}
	void deActivate() {
		isActive = false;
	}
	bool isShooting() {
		return isActive;
	}

	void draw() override {
		if (isActive) {
			Config::gotoxy(x, y);
			std::cout << "o";
		}
	}
};