#pragma once
#include <vector>
#include "Position.h"
#include "Config.h"
#include "raylib.h"
using namespace std;

class Block {
private:
    void init();
protected:
    int state;
    int offsetRow;
    int offsetCol;
    Color color;
    int SIGN;
    vector<vector<Position>> cells;
public:

    static const vector<Color> COLORS;
    Block();
    void draw();
    void rotateRight();
    void rotateLeft();
    vector<Position> getPositions();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getSign();
    vector<Position> getMatrix();
    Color getColor();
};