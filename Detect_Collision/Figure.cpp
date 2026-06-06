#include "Gun.cpp"

class Figure : public Object {
private:
	Gun *gun;
public:
	int life;
	Figure() {

	}
	Figure(Vector2D position,int speed) {
		gun = new Gun(position);
		this->position = position;
		this->speed = speed;
		life = 10;
	}
	~Figure() {
		delete gun;
	}


	void input() {
		if (IsKeyDown(KEY_A)) {
			moveLeft();
		}
		if (IsKeyDown(KEY_D)) {
			moveRight();
		}
		if (IsKeyDown(KEY_S)) {
			moveDown();
		}
		if (IsKeyDown(KEY_W)) {
			moveUp();
		}

		if (IsKeyPressed(KEY_J)) {
			gun->shoot();
		}
	}

	void moveLeft() {
		direction.x = -1;
	}
	void moveRight() {
		direction.x = 1;
	}
	void moveUp() {
		direction.y = -1;
	}
	void moveDown() {
		direction.y = 1;
	}

	void checkGunHitTo(Figure* fg) {
		if (gun->checkCollision(fg)) {
			fg->takeDamage(gun->getDamage());
		}
	}


	void update(float deltaTime) override {
		direction.reset();
		input();
		if (direction.x != 0 && direction.y != 0) {
			direction = direction.normalize();
		}
		position = position + direction * speed * deltaTime;
		gun->setPosition(this->position);


		gun->update(deltaTime);

	}
	void draw() override {
		DrawCircle(position.x, position.y, 20, BLUE);
		gun->draw();
	}

	void takeDamage(int damage) {
		life -= damage;
	}
	int getLife() {
		return life;
	}
};