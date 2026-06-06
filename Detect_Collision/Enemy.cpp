#include "Figure.cpp"

class Enemy :public Figure {
public:
	Enemy(Vector2D position, float speed) {
		this->position = position;
		this->speed = speed;
		life = 10;
	}
	void moveTo(Object* oj) {
		Vector2D ojPos = oj->getPosition();
		direction = (ojPos - position).normalize();
	}
	void update(float deltaTime) override {
		position = position + direction * speed * deltaTime;
	}
	void draw() override {
		DrawCircle(position.x, position.y, 20, BLACK);
	}
};