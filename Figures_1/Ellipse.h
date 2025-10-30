#pragma once
#include "Figure.h"

class Ellipse : public Figure { 
protected:
 double a;
 double b;

public:
 Ellipse(double a, double b);
 double perimeter() const override;
 double area() const override;
};

class Circle : public Ellipse {
 public:
  Circle(double r);
  double perimeter() const override;
  double area() const override;
};
