#include "SpaceShip.cpp"
#include <ctime>


class EnemySpaceShip : public SpaceShip {
private:
	int n = 6;
	int dx[6] = { 0, 0, 0, 0, 0, 0 };
	int dy[6] = { 1, -1, 1, -1, 2, -2 };
public:
	EnemySpaceShip() {
		srand(time(NULL));
		width = 3;
		height = 5;
		this->x = Config::WIDTH - height - 5;
		this->y =1 + rand() % (Config::HEIGHT-height);
		shootDelayTime.setDelayTime(750);
		moveDelayTime.setDelayTime(75);
		setOldXY(x, y);
		setHeath(2);
	}
	void shoot() {
		if (canShoot) {
			bullets.push_back(new Bullet(x, y + 2, 1, Config::DIRECTION_LEFT));
			canShoot = false;
		}
	}

	void move() override {
		if (canMove) {
			setOldXY(x, y);
			erase();
			int randomIndex = rand() % n;
			this->x += dx[randomIndex];
			this->y += dy[randomIndex];
			canMove = false;
		}
	}
	void draw() override {
		Config::gotoxy(x, y);     std::cout << "  __";
		Config::gotoxy(x, y + 1); std::cout << "/[  \\";
		Config::gotoxy(x, y + 2); std::cout << "  0++";
		Config::gotoxy(x, y + 3); std::cout << "\\[__/";

		if (!bullets.empty()) {
			drawBullets();
		}
	}

	void erase() {
		Config::gotoxy(x, y);     std::cout << "      ";
		Config::gotoxy(x, y + 1); std::cout << "      ";
		Config::gotoxy(x, y + 2); std::cout << "      ";
		Config::gotoxy(x, y + 3); std::cout << "      ";
	}
	void update() {
		shoot();
		move();
		SpaceShip::update();
	}

};

