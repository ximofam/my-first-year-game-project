
#include <iostream>
#include <vector>
#include "Bullet.cpp"
#include "DelayTime.cpp"

class SpaceShip : public Object {
protected:
	int heath;
	int oldX, oldY;
	bool canShoot = true;
	DelayTime shootDelayTime = DelayTime();
	bool canMove = true;
	DelayTime moveDelayTime = DelayTime();
	std::vector<Bullet*> bullets;

public:
	SpaceShip() {

	}
	SpaceShip(int x, int y) {
		setOldXY(x, y);
		width = 8;
		height = 3;
		this->x = x;
		this->y = y;
		shootDelayTime.setDelayTime(75);
		moveDelayTime.setDelayTime(25);
		setHeath(10);
	}
	~SpaceShip() {
		for (auto& bullet : bullets) {
			bullet->erase();
			delete bullet;
		}
	}
	void shoot() {
		if (canShoot) {
			bullets.push_back(new Bullet(x + 8, y + 1, 2));
			bullets.push_back(new Bullet(x + 8, y + 3, 2));
			canShoot = false;
		}
	}

	void moveUp() {
		if (canMove) {
			setOldXY(x, y);
			erase();
			y--;
			canMove = false;
		}
	}
	void moveDown() {
		if (canMove) {
			setOldXY(x, y);
			erase();
			y++;
			canMove = false;
		}
	}
	void moveLeft() {
		setOldXY(x, y);
		erase();
		x--;
	}
	void moveRight() {
		setOldXY(x, y);
		erase();
		x++;
	}

	void move() override {

		if (GetAsyncKeyState(VK_UP))
			moveUp();
		else if (GetAsyncKeyState(VK_DOWN))
			moveDown();
		else if (GetAsyncKeyState(VK_LEFT))
			moveLeft();
		else if (GetAsyncKeyState(VK_RIGHT))
			moveRight();

		if (GetAsyncKeyState('Z')) {
			shoot();
		}
	}

	bool checkBulletsCollision(Object* oj) {
		if (oj->getClassName() == "SpaceShip") {
			for (auto& bullet : bullets) {
				if (bullet->checkCollision(oj)) {
					bullet->deActivate();
					return true;
				}
			}
		}
		return false;
	}

	bool checkCollision(Object *oj) override {
		auto ship = dynamic_cast<SpaceShip*>(oj);
		if (checkBulletsCollision(ship)) {
			ship->descHeath();
		}
		if (ship->checkBulletsCollision(this)) {
			this->descHeath();
		}
		return true;
	}
	bool checkCollision() override {
		return (x <= 0 || x >= Config::WIDTH || y <= 0 || y >= Config::HEIGHT);
	}
	

	void update() {
		if (heath <= 0) return;



		for (auto& bullet : bullets) {
			bullet->move();
			if (bullet->checkCollision())
				bullet->deActivate();
		}
		

		
		for (int i = 0; i < bullets.size(); i++) {
			if (bullets[i]->isShooting() == false) {
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
			}
		}
		
		

		if (!canShoot) {
			if (shootDelayTime.checkTime(Config::deltaTime))
				canShoot = true;
		}

		if (!canMove) {
			if (moveDelayTime.checkTime(Config::deltaTime))
				canMove = true;
		}

		if (checkCollision()) {
			this->x = oldX;
			this->y = oldY;
		}
	}

	void drawBullets() {
		for (auto& bullet : bullets) {
			bullet->draw();
		}
	}

	std::string getClassName() override {
		return "SpaceShip";
	}

	void erase() {
		Config::gotoxy(x, y);     std::cout << "     ";
		Config::gotoxy(x, y + 1); std::cout << "        ";
		Config::gotoxy(x, y + 2); std::cout << "        ";
		Config::gotoxy(x, y + 3); std::cout << "       ";
	}

	void draw() override {
		if (heath <= 0) return;
		Config::gotoxy(x, y);     std::cout << "   __";
		Config::gotoxy(x, y + 1); std::cout << ">@|  \\=";
		Config::gotoxy(x, y + 2); std::cout << "  ()))))";
		Config::gotoxy(x, y + 3); std::cout << ">@|__/=";
		if (!bullets.empty()) {
			drawBullets();
		}
	}


	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	void setOldXY(int x, int y) {
		this->oldX = x;
		this->oldY = y;
	}
	void setHeath(int heath) {
		this->heath = heath;
	}
	void descHeath() {
		heath--;
	}
	int getHeath() {
		return heath;
	}
};