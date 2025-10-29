#pragma once
#include "Figure.h"

class Polygon : public Figure {};

class Triangle : public Polygon {
 protected:
  double a, b, c;

 public:
  Triangle(double s1, double s2, double s3);
  double area() const override;
  double perimeter() const override;
};

class IsoscelesTriangle : public Triangle {
 public:
  IsoscelesTriangle(double base, double equalSide);
  double area() const override;
  double perimeter() const override;
};

class EquilateralTriangle : public IsoscelesTriangle {
 public:
  EquilateralTriangle(double side);
  double area() const override;
  double perimeter() const override;
};

class Rectangle : public Polygon {
 private:
  double a, b;

 public:
  Rectangle(double s1, double s2);
  Rectangle() = default;
  double area() const override;
  double perimeter() const override;
};

class Square : public Rectangle {
 private:
  double a;

 public:
  Square(double s1);
  double area() const override;
  double perimeter() const override;
};

class Parallelogram : public Polygon {
 private:
  double a, b, h;

 public:
  Parallelogram(double s1, double s2, double s3);
  Parallelogram() = default;
  double area() const override;
  double perimeter() const override;
};

class Rhomb : public Parallelogram {
 private:
  double a, d1, d2;

 public:
  Rhomb(double s1, double s2, double s3);
  double area() const override;
  double perimeter() const override;
};