#pragma once
class Snake
{
	int x, y;
	// Point position;
	// std::vector<Point> tail;
public:
	Snake(int, int);
	int getX() const { return x; }
	int getY() const { return y; }
};
