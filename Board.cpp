#include "Board.h"

/**
 * @brief Constructor for the Board class.
 */
Board::Board() : width(WIDTH), height(HEIGHT) {}

/**
 * @brief Gets the width of the board.
 * @return The width of the board.
 */
int Board::getWidth() const {
    return width;
}

/**
 * @brief Gets the height of the board.
 * @return The height of the board.
 */
int Board::getHeight() const {
    return height;
}
