#include "Ellipse.h"

double Ellipse::perimeter() const { return -1; }
double Ellipse::area() const { return 3.14 * Ellipse::a * Ellipse::b; }

double Circle::perimeter() const { return 2 * 3.14 * r; }
double Circle::area() const { return 3.14 * Circle::r * Circle::r; }