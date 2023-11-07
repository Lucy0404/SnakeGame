#pragma once
#include "Board.h"
#include "Snake.h"
#include "defines.h"
#include "Fruits.h"

class GameEngine
{
public:
    GameEngine();
    void RunGame();

private:
    Board board;
    Snake snake;
    Fruits apple;
    Directions way;
    bool GameOver;

    void DrawBoard();
    void ProcessInput();
    void UpdateGame();
};
