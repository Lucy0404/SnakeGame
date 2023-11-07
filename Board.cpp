#include "Board.h"

Board::Board() : width(WIDTH), height(HEIGHT) {}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}
