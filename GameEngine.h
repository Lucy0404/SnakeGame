#pragma once
#include "Board.h"
#include "Snake.h"
#include "defines.h"
#include "Fruits.h"

class GameEngine
{
public:
	Board board;
	Snake snake;
	Fruits apple;
	Directions way;

	bool GameOver; // is game over or not

	GameEngine();
	void DrawBoard();
	void ProcessInput();
	void UpdateGame();
};
