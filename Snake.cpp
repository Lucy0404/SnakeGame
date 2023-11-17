#include "Snake.h"
#include "Fruits.h"
#include "Board.h"
#include <algorithm>

/**
 * @brief Constructor for the Snake class.
 * @param board Reference to the game board.
 */
Snake::Snake(const Board& board) : x(board.getWidth() / 2), y(board.getHeight() / 2), score(0), tailLength(0) {}

/**
 * @brief Gets the x-coordinate of the snake head.
 * @return The x-coordinate of the snake head.
 */
int Snake::getX() const {
    return x;
}

/**
 * @brief Gets the y-coordinate of the snake head.
 * @return The y-coordinate of the snake head.
 */
int Snake::getY() const {
    return y;
}

/**
 * @brief Gets the length of the snake tail.
 * @return The length of the snake tail.
 */
int Snake::getTailLength() const {
    return tailLength;
}

/**
 * @brief Gets the x-coordinate of a specific segment in the snake tail.
 * @param index The index of the tail segment.
 * @return The x-coordinate of the specified tail segment.
 */
int Snake::getTailX(int index) const {
    return tailX[index];
}

/**
 * @brief Gets the y-coordinate of a specific segment in the snake tail.
 * @param index The index of the tail segment.
 * @return The y-coordinate of the specified tail segment.
 */
int Snake::getTailY(int index) const {
    return tailY[index];
}

/**
 * @brief Gets the current score of the snake.
 * @return The current score of the snake.
 */
int Snake::getScore() const {
    return score;
}

/**
 * @brief Moves the snake in the specified direction.
 * @param way The direction in which the snake should move.
 * @param apple The current fruit in the game.
 * @param GameOver Flag indicating whether the game is over.
 * @param board Reference to the game board.
 */
void Snake::Move(Directions way, Fruits& apple, bool& GameOver, const Board& board) {
    // Keep the previous head position
    int prevX = x;
    int prevY = y;

    // Update the head position in accordance with the selected direction (way)
    switch (way) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Checking for collisions with borders
    if (x < 0 || x >= board.getWidth() || y < 0 || y >= board.getHeight()) {
        GameOver = true;
    }

    for (int i = 0; i < tailLength; i++) {
        int prevTailX = tailX[i];
        int prevTailY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prevTailX;
        prevY = prevTailY;

        // Using STL find for horizontal tail collision test
        auto collision = std::find(tailX.begin(), tailX.end(), x);
        if (collision != tailX.end() && tailY[std::distance(tailX.begin(), collision)] == y) {
            GameOver = true;
        }

        // Using STL find for vertical tail collision test
        auto collisionY = std::find(tailY.begin(), tailY.end(), y);
        if (collisionY != tailY.end() && tailX[std::distance(tailY.begin(), collisionY)] == x) {
            GameOver = true;
        }
    }

    if (x == apple.getX() && y == apple.getY()) {
        score += 10;
        tailX.push_back(prevX);
        tailY.push_back(prevY);
        tailLength++;
        apple.Respawn(board);
    }
}