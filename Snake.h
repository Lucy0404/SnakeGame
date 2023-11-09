#pragma once
#include <vector> // for containers
#include "Fruits.h"
#include "Board.h"

class Snake{
public:
    Snake(const Board& board);
    int getX() const;
    int getY() const;
    int getTailLength() const;
    int getTailX(int index) const;
    int getTailY(int index) const;
    int getScore() const;

    void Move(Directions way, Fruits& apple, bool& GameOver, const Board& board);

private:
    int x;
    int y;
    int score;
    int tailLength;
    // usage of containers
    std::vector<int> tailX;
    std::vector<int> tailY;
};
