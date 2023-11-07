#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include "main.h"

void Initialize() {
	GameOver = false;
	way = STOP;

	y = height / 2;
	x = width / 2;

	fruitX = rand() % width;
	fruitY = rand() % height;
}

void DrawBoard() {
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0)
				cout << "|";
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
				cout << "o";
			else
			{
				bool print = false;
				for (int k = 0; k < nSnakeTail; k++) {

					if (SnakeTailX[k] == j && SnakeTailY[k] == i) {
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == width - 1)
				cout << "|";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "-";
	cout << endl;
	cout << "\nScore: " << score << endl;
}

void ProcessInput() {
	if (_kbhit()) { //if keyboard key is pressed
		switch (_getch()) {
		case 'a':
			way = LEFT;
			break;
		case 'd':
			way = RIGHT;
			break;
		case 'w':
			way = UP;
			break;
		case 's':
			way = DOWN;
			break;
		case 'x':
			GameOver = true;
			break;
		}
	}
}

void UpdateGame() {
	int prevX = SnakeTailX[0];
	int prevY = SnakeTailY[0];
	int prev2X, prev2Y;
	SnakeTailX[0] = x;
	SnakeTailY[0] = y;
	for (int i = 1; i < nSnakeTail; i++) {
		prev2X = SnakeTailX[i];
		prev2Y = SnakeTailY[i];
		SnakeTailX[i] = prevX;
		SnakeTailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (way) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	if (x > width || x < 0 || y > height || y < 0) {
		GameOver = true;
	}

	for (int i = 0; i < nSnakeTail; i++) {
		if (SnakeTailX[i] == x && SnakeTailY[i] == y) {
			GameOver = true;
		}
	}

	if (x == fruitX && y == fruitY) {

		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nSnakeTail++;
	}
}

int main() {
	// usage of std::string
	std::string first = "Hello, player!";
	std::string second = "Good luck and have fun, ";
	std::string emptyString;
	std::string name;

	std::cout << first << std::endl;
	std::cout << emptyString << std::endl;
	std::cout << "Introduce yourself: ";
	std::cin >> name;
	std::cout << emptyString << std::endl;
	std::cout << second + name + " :)" << std::endl;
	std::cout << emptyString << std::endl;

	Initialize();

	while (!GameOver) {
		DrawBoard();
		ProcessInput();
		UpdateGame();
		Sleep(40);
	}

	return 0;
}