#include "Vector_math.h"
#include <math.h>

float MagnitudeSqrt(Vector2 v) {
	return v.x * v.x + v.y * v.y;
}

float Magnitude(Vector2 v) {
	return sqrt(MagnitudeSqrt(v));
}

Vector2 NormalizeVector(Vector2 v) {
	float magnitude = Magnitude(v);
	return { v.x / magnitude, v.y / magnitude };
}

Vector2 Subtract(Vector2 a, Vector2 b) {
	return { a.x - b.x, a.y - b.y };
}

Vector2 Add(Vector2 a, Vector2 b) {
	return { a.x + b.x, a.y + b.y };
}

Vector2 Scale(Vector2 v, float scalar) {
	return { v.x * scalar, v.y * scalar };
}
