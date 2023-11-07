#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool GameOver; // is game over or not

const int height = 20; //board measurements
const int width = 40; //board measurements

struct Point {
	int x, y;
};

int x, y, fruitX, fruitY, score; // for coords and score
//Point current;
//Point fruitPosition;
int SnakeTailX[100], SnakeTailY[100];
// std::vector<Point> SnakeTail;
int nSnakeTail;

enum Directions { STOP = 0, LEFT, RIGHT, UP, DOWN };
Directions way;