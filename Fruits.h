#pragma once
class Fruits
{
	int x, y;
	// Point position;
public:
	Fruits(int, int);
	Fruits() = default;
	Fruits(const Fruits&);

	int getX() const { return x; }
	int getY() const { return y; }
};