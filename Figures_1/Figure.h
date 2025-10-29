#pragma once
class Figure {
 public:
  double virtual perimeter() const = 0;
  double virtual area() const = 0;
  virtual ~Figure() = default;
};
