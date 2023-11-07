#include "Fruits.h"
#include <cstdlib>
#include <ctime>

Fruits::Fruits(const Board& board) {
    Respawn(board);
}

void Fruits::Respawn(const Board& board) {
    srand(static_cast<unsigned int>(time(0)));

    x = rand() % board.getWidth();
    y = rand() % board.getHeight();   
}

int Fruits::getX() const {
    return x;
}

int Fruits::getY() const {
    return y;
}
