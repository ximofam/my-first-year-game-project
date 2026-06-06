#include "raylib.h"
#include <vector>
#include <ctime>
using namespace std;
#define WIDTH 600
#define HEIGHT 600
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
struct Position {
	int x, y;
};

class Snake {
private:
	vector<Position> segments;
	int size;
	int direction;
public:
	Snake() {
		size = 20;
		Position pos = { 15 * 20,15 * 20 };
		segments.push_back(pos);
		direction = RIGHT;
	}
	void draw() {
		for (Position segment : segments) {
			DrawRectangle(segment.x, segment.y, size-1, size-1, RED);
		}
	}
	void move() {
		for (int i = segments.size() - 1; i > 0; i--) {
			segments[i] = segments[i - 1];
		}
		if (direction == LEFT) {
			segments[0].x -= size;
		}
		else if (direction == RIGHT) {
			segments[0].x += size;
		}
		else if (direction == UP) {
			segments[0].y -= size;
		}
		else if (direction == DOWN) {
			segments[0].y += size;
		}
	}
	int getSize() {
		return size;
	}
	void setDirection(int d) {
		direction = d;
	}
	int getDirection() {
		return direction;
	}
	void growUp() {
		segments.push_back(segments[segments.size() - 1]);
	}
	Position getPos() {
		return segments[0];
	}
	int getPosX() {
		return segments[0].x;
	}
	int getPosY() {
		return segments[0].y;
	}
};
class Fruit {
private:
	Position pos;
public:
	bool isActive;
	Fruit() {
		reset();
	}
	void draw(){
		DrawCircle(pos.x + 10, pos.y + 10, 7, BLUE);
	}
	void reset() {
		srand(time(NULL));
		isActive = true;
		pos.x = (rand() % 30) * 20;
		pos.y = (rand() % 30) * 20;
	}
	Position getPos() {
		return pos;
	}
	int getPosX() {
		return pos.x;
	}
	int getPosY() {
		return pos.y;
	}
};

Snake snake;
Fruit fruit;

void update() {
	
	if (fruit.isActive == false) {
		snake.growUp();
		fruit.isActive = true;
		fruit.reset();
	}

	if (snake.getDirection()!=RIGHT && IsKeyDown(KEY_LEFT)) {
		snake.setDirection(LEFT);
	}
	else if (snake.getDirection() != LEFT && IsKeyDown(KEY_RIGHT)) {
		snake.setDirection(RIGHT);
	}
	else if (snake.getDirection() != UP &&  IsKeyDown(KEY_DOWN)) {
		snake.setDirection(DOWN);
	}
	else if(snake.getDirection() != DOWN &&  IsKeyDown(KEY_UP)){
		snake.setDirection(UP);
	}

	snake.move();

	
}

void checkCollision() {
	if (snake.getPosX() == fruit.getPosX() && snake.getPosY()==fruit.getPosY()) {
		fruit.isActive = false;
	}


}

void draw() {
	ClearBackground(GRAY);
	for (int i = 1; i < 30; i++) {
		DrawLine(snake.getSize() * i, 0, snake.getSize() * i, HEIGHT, WHITE);
		DrawLine(0, snake.getSize() * i, WIDTH, snake.getSize() * i, WHITE);
	}
	snake.draw();
	if(fruit.isActive)
		fruit.draw();
}




int main() {
	InitWindow(WIDTH, HEIGHT, "Demo");
	SetTargetFPS(10);


	
	while (WindowShouldClose() == false) {
		//update
		update();
		//check collision
		checkCollision();
		//draw
		BeginDrawing();
		draw();
		EndDrawing();
	}

	CloseWindow();

	return 1;
}