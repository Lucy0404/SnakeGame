#pragma once
#include "defines.h"

class Board
{
	int width;
	int height;
public:
	Board(int, int);
	int getWidth() const;
	int getHeight() const;
};