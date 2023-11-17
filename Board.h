/**
 * @file Board.h 
 * @author Garichina Maria
 * @date 2023
 */
#pragma once
#include "defines.h"

/**
 * @brief Represents the game board.
 */
class Board{
public:
    /**
     * @brief Constructor for the Board class.
     */
    Board();

    /**
     * @brief Gets the width of the board.
     * @return The width of the board.
     */
    int getWidth() const;

    /**
     * @brief Gets the height of the board.
     * @return The height of the board.
     */
    int getHeight() const;

private:
    int width; ///< The width of the board.
    int height; ///< The height of the board.
};
