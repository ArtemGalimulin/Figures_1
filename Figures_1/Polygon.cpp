

#include "Polygon.h"
#include "Figure.cpp"

#include <cmath>

class Polygon : public Figure {
	double virtual perimeter() const = 0;
	double virtual area() const = 0;
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
private:
	double a, b, h;
public:
	Parallelogram(double s1, double s2, double s3) : a(s1) , b(s2), h(s3){};
	Parallelogram() = default;
	double area() const override {
		return a * h;;
	}
	double perimeter() const override {
		return (a + b) * 2;
	}
};

class Rhomb : public Parallelogram {
private:
	double a, d1, d2;
public:
	Rhomb(double s1, double s2, double s3) : a(s1), d1(s2), d2(s3) {};
	double area() const override {
		return 0.5 * d1 * d2;
	}
	double perimeter() const override {
		return a * 4;
	}
};