#include "Polygon.h"
#include <cmath>


Triangle::Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}
double Triangle::area() const {
  double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
double Triangle::perimeter() const { return a + b + c; }


Rectangle::Rectangle(double s1, double s2) : a(s1), b(s2) {}
double Rectangle::area() const { return a * b; }
double Rectangle::perimeter() const { return 2 * (a + b); }


Square::Square(double s1) : a(s1) {}
double Square::area() const { return a * a; }
double Square::perimeter() const { return 4 * a; }


Parallelogram::Parallelogram(double s1, double s2, double s3)
    : a(s1), b(s2), h(s3) {}
double Parallelogram::area() const { return a * h; }
double Parallelogram::perimeter() const { return 2 * (a + b); }


Rhomb::Rhomb(double s1, double s2, double s3) : a(s1), d1(s2), d2(s3) {}
double Rhomb::area() const { return 0.5 * d1 * d2; }
double Rhomb::perimeter() const { return 4 * a; }