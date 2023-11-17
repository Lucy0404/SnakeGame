/**
 * @file GameEngine.h 
 * @author Garichina Maria
 * @date 2023
 */
#pragma once
#include "Board.h"
#include "Snake.h"
#include "defines.h"
#include "Fruits.h"

/**
 * @brief Represents the game engine that controls the game flow.
 */
class GameEngine
{
public:
    /**
     * @brief Constructor for the GameEngine class.
     */
    GameEngine();

    /**
     * @brief Runs the game loop.
     */
    void RunGame();

private:
    Board board; ///< The game board.
    Snake snake; ///< The game snake.
    Fruits apple; ///< The game fruit.
    Directions way; ///< Current direction of the snake. 
    bool GameOver; ///< Flag indicating whether the game is over. 

    /**
     * @brief Draws the game board on the console.
     */
    void DrawBoard();

    /**
     * @brief Processes user input.
     */
    void ProcessInput();

    /**
     * @brief Updates the game state.
     */
    void UpdateGame();
};
