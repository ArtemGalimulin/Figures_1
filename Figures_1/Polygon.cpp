

#include "Polygon.h"
#include "Figure.cpp"

#include <cmath>

class Polygon : public Figure {
	//too hard
};

class Triangle : public Polygon {
private:
	double a, b, c;
public:
	Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {};
	double area() const override{
		double p = (a + b + c) / 2;
		return std::sqrt(p * (p - a) * (p - b) * (p - c));
	}
	double perimeter() const override {
		return a + b + c;
	}
};

class Rectangle : public Polygon {
private:
	double a, b;
public:
	Rectangle(double s1, double s2) : a(s1), b(s2) {};
	Rectangle() = default;
	double area() const override {
		return a * b;;
	}
	double perimeter() const override {
		return a + b + a + b;
	}
};

class Square : public Rectangle {
private:
	double a;
public:
	Square(double s1) : a(s1) {};
	double area() const override {
		return a * a;;
	}
	double perimeter() const override {
		return a * 4;
	}
};

class Parallelogram : public Polygon {

};

class Rhomb : public Parallelogram {

};