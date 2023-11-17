/**
 * @file Fruits.h 
 * @author Garichina Maria
 * @date 2023
 */
#pragma once
#include "Board.h"

/**
 * @brief Represents the fruits in the game.
 */
class Fruits{
public:
    /**
     * @brief Constructor for the Fruits class.
     * @param board Reference to the game board.
     */
    Fruits(const Board& board);

    /**
     * @brief Respawns the fruit at a new random position on the board.
     * @param board Reference to the game board.
     */
    void Respawn(const Board& board);

    /**
     * @brief Gets the X-coordinate of the fruit.
     * @return The X-coordinate of the fruit.
     */
    int getX() const;

    /**
     * @brief Gets the Y-coordinate of the fruit.
     * @return The Y-coordinate of the fruit.
     */
    int getY() const;

private:
    int x; ///< The x-coordinate of the fruit.
    int y; ///< The y-coordinate of the fruit.
};
