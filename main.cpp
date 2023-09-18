#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool GameOver; // is game over or not

const int height = 20; //board measurements 
const int width = 40;  //board measurements 

int x, y, fruitX, fruitY, score; // for coords

int SnakeTailX[100], SnakeTailY[100];
int nSnakeTail;

enum Directions { STOP = 0, UP, DOWN, LEFT, RIGHT };
Directions way;

void Initialize() {
	GameOver = false;
	way = STOP;

	y = height / 2;
	x = width / 2;

	fruitX = rand() % width;
	fruitY = rand() % height;
}

void DrawBoard() {

}

void ProcessInput() {

}

void UpdateGame() {


}

int main() {

	Initialize();

	while (!GameOver) {
		DrawBoard();
		ProcessInput();
		UpdateGame();
	}

	return 0;
}