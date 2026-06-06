#include "Object.cpp"


class Bullet : public Object {
private:
	bool active;
	int size;
public:
	Bullet(Vector2D position, Vector2D direction, float speed) {
		this->position = position;
		this->direction = direction;  
		this->speed = speed;
		active = true;
		size = 5;
	}
	void deActive() {
		active = false;
	}
	bool isActive() {
		return active;
	}

	void update(float deltaTime) override{
		if (active) {
			position = position + direction * speed * deltaTime;
		}
	}

	bool checkCollision() {
		if (position.x <= 0 || position.x >= GetScreenWidth() ||
			position.y <= 0 || position.y >= GetScreenHeight()) return true;
		return false;
	}

	void draw() override {
		if (active) {
			DrawCircle(position.x, position.y, size, RED);
		}
	}
};