#include <cmath>
#include "Ellipse.h"

Ellipse::Ellipse(double a, double b) : a(a), b(b) {}
double Ellipse::perimeter() const {
  return 3.14 * (3 * (a + b) -
                 std::sqrt((3 * a + b) * (a + 3 * b)));  // приблизительно
}
double Ellipse::area() const { return 3.14 * a * b; }

Circle::Circle(double r) : Ellipse(r, r) {}
double Circle::perimeter() const { return 2 * 3.14 * a; }
double Circle::area() const { return 3.14 * a * a; }