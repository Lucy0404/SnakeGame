#pragma once
class Fruits
{
	int x, y;
public:
	Fruits(int, int);
	Fruits() = default;
	Fruits(const Fruits&);
};