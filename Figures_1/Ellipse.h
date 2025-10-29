#pragma once
#include "Figure.h"

class Ellipse : public Figure { 
 double a = 1.0;
 double b = 1.0;

public:
 Ellipse(double a, double b) : a(a), b(b) {}
 Ellipse() = default;
 double perimeter() const;
 double area() const;
};

class Circle : public Ellipse {
  double r;
  Circle(double r) : r(r) {}

 public:
  double perimeter() const;
  double area() const;
};
