/**
 * @file Snake.h
 * @author Garichina Maria
 * @date 2023
 */
#pragma once
#include <vector> // for containers
#include "Fruits.h"
#include "Board.h"

/**
 * @brief Represents the game snake.
 */
class Snake{
public:
    /**
     * @brief Constructor for the Snake class.
     * @param board Reference to the game board.
     */
    Snake(const Board& board);

    /**
     * @brief Gets the x-coordinate of the snake head.
     * @return The x-coordinate of the snake head.
     */
    int getX() const;

    /**
     * @brief Gets the y-coordinate of the snake head.
     * @return The y-coordinate of the snake head.
     */
    int getY() const;

    /**
     * @brief Gets the length of the snake tail.
     * @return The length of the snake tail.
     */
    int getTailLength() const;
    int getTailX(int index) const;
    int getTailY(int index) const;

    /**
     * @brief Gets the current score of the snake.
     * @return The current score of the snake.
     */
    int getScore() const;

    /**
     * @brief Moves the snake in the specified direction.
     */
    void Move(Directions way, Fruits& apple, bool& GameOver, const Board& board);

private:
    int x;///< The x-coordinate of the snake head.
    int y; ///< The y-coordinate of the snake head.
    int score; ///< The current score of the snake.
    int tailLength; ///< The length of the snake tail.
    // usage of containers
    std::vector<int> tailX;///< Vector storing the x-coordinates of the snake tail segments.
    std::vector<int> tailY; ///< Vector storing the y-coordinates of the snake tail segments.
};
