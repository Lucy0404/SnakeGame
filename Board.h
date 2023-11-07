#pragma once
#include "defines.h"

class Board{
public:
    Board();
    int getWidth() const;
    int getHeight() const;

private:
    int width;
    int height;
};
