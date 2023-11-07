#include "Board.h"

Board::Board(int w, int h) : width(w), height(h) {
}

int Board::getWidth() const {
	return width;
};
int Board::getHeight() const {
	return height;
};