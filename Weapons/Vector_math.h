#pragma once
#include "raylib.h"


float MagnitudeSqrt(Vector2 v);
float Magnitude(Vector2 v);
Vector2 NormalizeVector(Vector2 v);
Vector2 Subtract(Vector2 a, Vector2 b);
Vector2 Add(Vector2 a, Vector2 b);
Vector2 Scale(Vector2 a, float scalar);
