#include "Fruits.h"
Fruits::Fruits(int a, int b) : x(a), y(b) {
}

Fruits::Fruits(const Fruits& fruit) : x(fruit.x), y(fruit.y) {
}