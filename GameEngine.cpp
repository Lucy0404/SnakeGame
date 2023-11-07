#include "GameEngine.h"
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <conio.h>

GameEngine::GameEngine() : board(), snake(board), apple(board), GameOver(false), way(STOP) {}

void GameEngine::RunGame() {
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

    Sleep(3000);

    while (!GameOver) {
        DrawBoard();
        ProcessInput();
        UpdateGame();
        Sleep(100);
    }
}

void GameEngine::DrawBoard() {
    system("cls");
    for (int i = 0; i < board.getWidth() + 2; i++)
        std::cout << "-";
    std::cout << std::endl;

    for (int i = 0; i < board.getHeight(); i++) {
        for (int j = 0; j < board.getWidth(); j++) {
            if (j == 0)
                std::cout << "|";
            if (i == snake.getY() && j == snake.getX())
                std::cout << "0";
            else if (i == apple.getY() && j == apple.getX())
                std::cout << "o";
            else {
                bool print = false;
                for (int k = 0; k < snake.getTailLength(); k++) {
                    if (snake.getTailX(k) == j && snake.getTailY(k) == i) {
                        std::cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    std::cout << " ";
            }
            if (j == board.getWidth() - 1)
                std::cout << "|";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < board.getWidth() + 2; i++)
        std::cout << "-";
    std::cout << std::endl;
    std::cout << "\nScore: " << snake.getScore() << std::endl;
}

void GameEngine::ProcessInput() {
    if (_kbhit()) { // if a key is pressed
        char key = _getch();
        switch (key) {
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
    snake.Move(way, apple, GameOver, board);
}
