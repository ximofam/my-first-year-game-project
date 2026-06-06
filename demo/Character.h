#pragma once
#include "Animation.h"

enum CharacterState{
	IDLE,RUN,ROLL,HIT,DEATH
};

class Character {
private:
	
	int state;
	vector<Animate> animation;
	Texture2D spriteSheet;
	void setAnimate(int speed) {
		spriteSheet = LoadTexture("knight.png");
		int frameWidth = 32;
		int frameHeight = 32;
		Animate idle(speed);
		for (int i = 0; i < 4; i++) {
			idle.addFrameRec({ (float)i * frameWidth,0,(float)frameWidth,(float)frameHeight });
		}
		animation.push_back(idle);

		Animate run(speed);
		for (int i = 0; i < 8; i++) {
			run.addFrameRec({ (float)i * frameWidth,2.0f * frameHeight,(float)frameWidth,(float)frameHeight });
		}
		for (int i = 0; i < 8; i++) {
			run.addFrameRec({ (float)i * frameWidth,3.0f * frameHeight,(float)frameWidth,(float)frameHeight });
		}
		animation.push_back(run);

		Animate roll(speed);
		for (int i = 0; i < 8; i++) {
			roll.addFrameRec({ (float)i * frameWidth,5.0f * frameHeight,(float)frameWidth,(float)frameHeight });
		}
		animation.push_back(roll);

		Animate hit(speed);
		for (int i = 0; i < 4; i++) {
			hit.addFrameRec({ (float)i * frameWidth,6.0f * frameHeight,(float)frameWidth,(float)frameHeight });
		}
		animation.push_back(hit);


		Animate death(speed);
		for (int i = 0; i < 4; i++) {
			death.addFrameRec({ (float)i * frameWidth,7.0f * frameHeight,(float)frameWidth,(float)frameHeight });
		}
		animation.push_back(death);
	}
public:
	Vector2 position;
	Vector2 v;
	bool isJumping;
	bool isRunning;
	float gravity;
	bool rotate;
	int width;
	int height;
	Character(Vector2 pos,int w,int h) {
		rotate = false;
		setAnimate(8);
		position = pos;
		width = w;
		height = h;
		state = IDLE;
		isJumping = false;
		isRunning = false;
		gravity = 500;
		v = { 0,0 };
	}
	~Character() {
		UnloadTexture(spriteSheet);
	}
	Vector2 getPosition() {
		return position;
	}
	void moveLeft(float speed) {
		rotate = true;
		v.x = -speed;
	}
	void moveRight(float speed) {
		rotate = false;
		v.x = speed;
	}
	void jump(float jumpForce) {
		if (isJumping == false) {
			v.y = jumpForce;
			isJumping = true;
		}
	}
	void setPosition(Vector2 pos) {
		position = pos;
	}
	void update(bool isOnFloor,const int fps) {

		

		animation[state].update(fps);
		float deltaTime = 1.0f / (float)fps;

		

		position.x = position.x + v.x * deltaTime;
		position.y = position.y + v.y * deltaTime;



		if (isOnFloor == false)
			v.y += gravity * deltaTime;
		else {

			v.y = 0;
			isJumping = false;
		}
	}

	void draw() {
		Rectangle source = animation[state].getCurrentFrame();
		if (rotate) {
			source.width *= -1;
		}
		/*DrawRectanglePro({ position.x,position.y,(float)width,(float)height }, { 0,0 }, 0, WHITE);
		DrawCircle((int)position.x, (int)position.y, 5, RED);*/
		DrawTexturePro(spriteSheet, source, { position.x,position.y,(float)width,(float)height }, { (float)width*0,(float)height*0}, 0, WHITE);
		
	}
	void changeState(int state) {
		if (state != this->state) {
			animation[this->state].reset();
			this->state = state;
		}
	}
};