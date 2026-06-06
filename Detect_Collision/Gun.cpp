#include "Bullet.cpp"
#include <vector>
#include "DelayTime.cpp"

class Gun : public Object {
private:
	int damage = 2;
	std::vector<Bullet*> bullets;
	DelayTime shootTime = DelayTime(0.1);
	bool canShoot = true;
public:
	Gun(Vector2D position) {
		this->position = position;
		speed = 0;
	}

	~Gun() {
		for (auto& bullet : bullets) {
			delete bullet;
		}
	}

	bool checkCollision(Object* oj) {
		
		for (auto& bullet : bullets) {
			Vector2D posPoint = bullet->getPosition();
			Vector2D posCir = oj->getPosition();
			if (CheckCollisionPointCircle({ posPoint.x, posPoint.y }, { posCir.x, posCir.y }, 20)) {
				bullet->deActive();
				return true;
			}
		}
		return false;
	}

	void shoot() {
		if (canShoot) {
			canShoot = false;
			shootTime.reset();
			bullets.push_back(new Bullet(this->position, this->direction, 750));
		}
	}
	
	void deleteBulletsUnActive() {
		for (int i = 0; i < bullets.size(); i++) {
			if (!bullets[i]->isActive()) {
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
			}
		}
	}


	void input() {
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			shoot();
		}

		Vector2 mouse = GetMousePosition();
		direction = Vector2D{ mouse.x, mouse.y } - position;
		direction = direction.normalize();
	}


	void update(float deltaTime) override {
		input();

		for (auto& bullet : bullets) {
			bullet->update(deltaTime);
		}
		

		for (auto& bullet : bullets) {
			if (bullet->checkCollision()) {
				bullet->deActive();
			}
		}

		deleteBulletsUnActive();


		if (shootTime.update(deltaTime)) {
			canShoot = true;
		}

	}

	void draw() override {
		DrawLine(position.x, position.y, position.x + direction.x * 50, position.y + direction.y * 50, RED);

		for (auto& bullet : bullets) {
			bullet->draw();
		}

	}

	int getDamage() {
		return damage;
	}
};