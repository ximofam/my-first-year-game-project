#include <Windows.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>


class Config {
public:
	static void gotoxy(int x, int y) {
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	static const int deltaTime = 16;
	static const int x = 50;
	static const int y = 5;
};