#include "raylib.h"
#include <utility>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;
#define WIDTH 1200
#define HEIGHT 800
struct Ball {
	Vector2 p,v,a;
	float r;
	int id;
	//float mass;
};
const int FPS = 300;
float deltaTime = 1.0f / (float)FPS;
vector<Ball> balls;
Ball* selectedBall = NULL;




void addBall(float x, float y, float r) {
	Ball b;
	b.p.x = x;
	b.p.y = y;
	b.r = r;
	//b.mass = r * 10.0f;
	b.v.x = b.v.y = 0.0f;
	b.a.x = b.a.y = 0.0f;
	b.id = balls.size();
	balls.push_back(b);
}
bool doCircleOverlap(Ball b1, Ball b2) {
	return ((b1.p.x - b2.p.x)*(b1.p.x - b2.p.x) + (b1.p.y - b2.p.y)*(b1.p.y - b2.p.y)) <= (b1.r + b2.r)*(b1.r + b2.r);
}
float calDistance(float x1,float y1,float x2,float y2) {
	return sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool isMouseInBall(Ball b, Vector2 mousePos) {
	return calDistance(b.p.x, b.p.y, mousePos.x, mousePos.y) < b.r;
}

void onUserCreate() {
	srand(time(NULL));


	for (int i = 0; i < 10; i++) {
		addBall(rand() % WIDTH, rand() % HEIGHT, 50.0f);
	}
}


void update() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		selectedBall = NULL;
		for (Ball& ball : balls) {
			if (isMouseInBall(ball, GetMousePosition())) {
				selectedBall = &ball;
				break;
			}
		}
	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && selectedBall != NULL) {
		Vector2 mousePos = GetMousePosition();
		selectedBall->v = { (selectedBall->p.x - mousePos.x) * 5.0f,(selectedBall->p.y - mousePos.y) * 5.0f };
		selectedBall = NULL;
	}

	// update ball position
	for (Ball& ball : balls) {

		ball.a.x = -ball.v.x * 0.8f;
		ball.a.y = -ball.v.y * 0.8f;
		ball.v.x += ball.a.x * deltaTime;
		ball.v.y += ball.a.y * deltaTime;
		ball.p.x += ball.v.x * deltaTime;
		ball.p.y += ball.v.y * deltaTime;


		if (ball.p.x - ball.r < 0) {
			ball.v.x *= -1;
			ball.p.x = ball.r;
		}
		else if (ball.p.x + ball.r > WIDTH) {
			ball.v.x *= -1;
			ball.p.x = WIDTH - ball.r;
		}

		if (ball.p.y - ball.r < 0) {
			ball.v.y *= -1;
			ball.p.y = ball.r;
		}
		else if (ball.p.y + ball.r > HEIGHT) {
			ball.v.y *= -1;
			ball.p.y = HEIGHT - ball.r;
		}
	}

	//static collision
	vector<pair<Ball*, Ball*>> ballCollided;
	for (Ball& ball : balls) {
		for (Ball& target : balls) {
			if (ball.id != target.id) {
				if (doCircleOverlap(ball, target)) {
					ballCollided.push_back({ &ball, &target });

					float distance = calDistance(ball.p.x, ball.p.y, target.p.x, target.p.y);

					float overLap = (ball.r + target.r - distance) * 0.5;
					ball.p.x += overLap * (ball.p.x - target.p.x) / distance;
					ball.p.y += overLap * (ball.p.y - target.p.y) / distance;

					target.p.x -= overLap * (ball.p.x - target.p.x) / distance;
					target.p.y -= overLap * (ball.p.y - target.p.y) / distance;

				}
			}
		}
	}
	//dynamic collision
	for (auto& c : ballCollided) {
		Ball* b1 = c.first;
		Ball* b2 = c.second;

		float distance = calDistance(b1->p.x, b1->p.y, b2->p.x, b2->p.y);

		float nx = (b2->p.x - b1->p.x) / distance;
		float ny = (b2->p.y - b1->p.y) / distance;

		//duong phap tuyen
		float tx = -ny;
		float ty = nx;

		//tich vo huong 
		float dpTan1 = b1->v.x * tx + b1->v.y * ty;
		float dpTan2 = b2->v.x * tx + b2->v.y * ty;

		/*float dpNormal1 = b1->v.x * nx + b1->v.y * ny;
		float dpNormal1 = b2->v.x * nx + b2->v.y * ny;*/




		b1->v.x = tx * dpTan1;
		b1->v.y = ty * dpTan1;
		b2->v.x = tx * dpTan2;
		b2->v.y = ty * dpTan2;

	}

}

void draw() {
	ClearBackground(GRAY);
	for (Ball &ball : balls) {
		DrawCircle(int(ball.p.x), int(ball.p.y), ball.r, DARKBLUE);
	}

	if (selectedBall != NULL) {
		DrawLineV(selectedBall->p, GetMousePosition(), RED);
	}
}

int main() {
	InitWindow(WIDTH, HEIGHT, "Demo");
	SetTargetFPS(FPS);
	onUserCreate();
	while (WindowShouldClose() == false) {
		update();
		BeginDrawing();
		draw();
		DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();
	return 1;
}