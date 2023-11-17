#include "Fruits.h"
#include <cstdlib>
#include <ctime>

/**
 * @brief Constructor for the Fruits class.
 * @param board Reference to the game board.
 */
Fruits::Fruits(const Board& board) {
    Respawn(board);
}

/**
 * @brief Respawn the fruit at a new random position on the board.
 * @param board Reference to the game board.
 */
void Fruits::Respawn(const Board& board) {
    srand(static_cast<unsigned int>(time(0)));

    x = rand() % board.getWidth();
    y = rand() % board.getHeight();   
}

/**
 * @brief Gets the x-coordinate of the fruit.
 * @return The x-coordinate of the fruit.
 */
int Fruits::getX() const {
    return x;
}

/**
 * @brief Gets the y-coordinate of the fruit.
 * @return The y-coordinate of the fruit.
 */
int Fruits::getY() const {
    return y;
}
