#pragma once
#include "Board.h"

class Fruits{
public:
    Fruits(const Board& board);
    void Respawn(const Board& board);
    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};
