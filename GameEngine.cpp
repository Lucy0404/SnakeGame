#include "GameEngine.h"
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

GameEngine::GameEngine() : board(WIDTH, HEIGHT), snake(board.getHeight() / 2, board.getWidth() / 2) {
	apple = Fruits(rand() % WIDTH, rand() % HEIGHT);
	GameOver = false;

	way = STOP;

}

void GameEngine::DrawBoard() {
	system("cls");
	for (int i = 0; i < board.getWidth() + 2; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < board.getHeight(); i++) {
		for (int j = 0; j < board.getWidth(); j++) {
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
			if (j == board.getWidth() - 1)
				cout << "|";
		}
		cout << endl;
	}

	for (int i = 0; i < board.getWidth() + 2; i++)
		cout << "-";
	cout << endl;
	cout << "\nScore: " << score << endl;
}

void GameEngine::ProcessInput() {
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

void GameEngine::UpdateGame() {

}