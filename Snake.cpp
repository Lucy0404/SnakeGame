#include "Snake.h"
#include "Fruits.h"
#include "Board.h"

Snake::Snake(const Board& board) : x(board.getWidth() / 2), y(board.getHeight() / 2), score(0), tailLength(0) {}

int Snake::getX() const {
    return x;
}

int Snake::getY() const {
    return y;
}

int Snake::getTailLength() const {
    return tailLength;
}

int Snake::getTailX(int index) const {
    return tailX[index];
}

int Snake::getTailY(int index) const {
    return tailY[index];
}

int Snake::getScore() const {
    return score;
}

void Snake::Move(Directions way, Fruits& apple, bool& GameOver, const Board& board) {
    // Сохраняем предыдущую позицию головы
    int prevX = x;
    int prevY = y;

    // Обновляем позицию головы в соответствии с выбранным направлением (way)
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

    // Проверяем столкновение с границами и хвостом
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

        if (tailX[i] == x && tailY[i] == y) {
            GameOver = true;
        }
    }

    // Отрисовка головы 
    if (x == apple.getX() && y == apple.getY()) {
        score += 10;
        tailX.push_back(prevX);
        tailY.push_back(prevY);
        tailLength++;
        apple.Respawn(board);
    }
}