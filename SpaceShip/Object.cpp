#include <string>


class Object {
protected:
	int x, y;
	int width, height;
public:
	Object() {
		
	}
	Object(int x, int y) {
		this->x = x;
		this->y = y;
	}
	virtual bool checkCollision() {
		return false;
	}

	virtual bool checkCollision(Object *oj) {
		return false;
	}

	virtual std::string getClassName() {
		return "";
	}

	virtual void move() {

	}

	virtual void draw() {
		
	}

	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
};