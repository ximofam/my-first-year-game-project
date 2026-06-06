#pragma once
#include <cmath>	
struct Vector2D {
	float x, y;

	float magnitude() {
		return sqrt(x * x + y * y);
	}
	float squareMagnitude() {
		return x * x + y * y;
	}

	void reset() {
		x = y = 0;
	}

	Vector2D normalize() {
		float length = magnitude();
		return { x / length,y / length };
	}


	Vector2D operator + (const Vector2D& other) {
		return { x + other.x,y + other.y };
	}
	Vector2D operator - (const Vector2D& other) {
		return { x - other.x,y - other.y };
	}
	Vector2D operator * (const Vector2D& other) {
		return { x * other.x,y * other.y };
	}
	Vector2D operator / (const Vector2D& other) {
		return { x / other.x,y / other.y };
	}
	Vector2D operator * (const float& num) {
		return { x * num,y * num };
	}
	Vector2D operator / (const float& num) {
		return { x / num,y / num };
	}
};