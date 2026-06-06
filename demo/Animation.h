#pragma once
#include <vector>
#include "raylib.h"
#include "iostream"
using namespace std;
class Animate {
private:
	vector<Rectangle> frameRec;
	int currentFrame;
	int speed;
	int count;
public:
	Animate(int speed) {
		reset();
		this->speed = speed;
	}
	void reset() {
		count = 0;
		currentFrame = 0;
	}
	void addFrameRec(Rectangle rec) {
		frameRec.push_back(rec);
	}
	void update(const int fps) {
		
		count += 1;
		if (count >= fps / speed) {
			count = 0;
			currentFrame++;
			if (currentFrame >= frameRec.size())
				currentFrame = 0;
		}
	}
	Rectangle getCurrentFrame() {
		return frameRec[currentFrame];
	}
};