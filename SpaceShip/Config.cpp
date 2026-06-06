#include <Windows.h>

class Config {
public:
	static void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    static bool checkCollision(int px, int py, int rx, int ry, int width, int height) {
        return (px >= rx && px <= rx + width &&
            py >= ry && py <= ry + height);
    }
    static const int WIDTH = 120;
    static const int HEIGHT = 30;
    static const int deltaTime = 16; // mili giay
    static const int DIRECTION_LEFT = -1;
    static const int DIRECTION_RIGHT = 1;
};