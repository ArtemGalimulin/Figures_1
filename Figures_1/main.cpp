// дз 3 задание 1 состоит из файлов фигур, которые в папке Figures_1 лежат

#include <iostream>
#include <vector>
#include "Ellipse.cpp"
#include "Figure.cpp"
#include "Polygon.cpp"

std::vector<Figure*> inputShapes() {
  std::vector<Figure*> shapes;
  int choice;
  while (true) {
    std::cout << "1-Triangle 2-Rectangle 3-Square 4-Circle 5-Ellipse "
                 "6-Isosceles 7-Equilateral 8-Parallelogram 9-Rhombus 0-Stop: "
              << '\n';
    std::cin >> choice;
    if (choice == 0) break;
    switch (choice) {
      case 1: {
        double a, b, c;
        std::cout << "3 sides: ";
        std::cin >> a >> b >> c;
        shapes.push_back(new Triangle(a, b, c));
        break;
      }
      case 2: {
        double a, b;
        std::cout << "length, width: ";
        std::cin >> a >> b;
        shapes.push_back(new Rectangle(a, b));
        break;
      }
      case 3: {
        double a;
        std::cout << "side: ";
        std::cin >> a;
        shapes.push_back(new Square(a));
        break;
      }
      case 4: {
        double r;
        std::cout << "radius: ";
        std::cin >> r;
        shapes.push_back(new Circle(r));
        break;
      }
      case 5: {
        double a, b;
        std::cout << "2 semi-axes: ";
        std::cin >> a >> b;
        shapes.push_back(new Ellipse(a, b));
        break;
      }
      case 6: {
        double base, side;
        std::cout << "base, equal side: ";
        std::cin >> base >> side;
        shapes.push_back(new IsoscelesTriangle(base, side));
        break;
      }
      case 7: {
        double side;
        std::cout << "side: ";
        std::cin >> side;
        shapes.push_back(new EquilateralTriangle(side));
        break;
      }
      case 8: {
        double a, b, h;
        std::cout << "base, side, height: ";
        std::cin >> a >> b >> h;
        shapes.push_back(new Parallelogram(a, b, h));
        break;
      }
      case 9: {
        double a, d1, d2;
        std::cout << "side, diagonal 1, diagonal 2: ";
        std::cin >> a >> d1 >> d2;
        shapes.push_back(new Rhomb(a, d1, d2));
        break;
      }
    }
  }
  return shapes;
}

void printAreasAndPerimeters(const std::vector<Figure*>& shapes) {
  for (int i = 0; i < shapes.size(); ++i) {
    std::cout << "Shape " << i + 1 << ": Area=" << shapes[i]->area()
              << ", Perimeter=" << shapes[i]->perimeter() << '\n';
  }
}

void deleteShapes(std::vector<Figure*>& shapes) {
  for (Figure* shape : shapes) {
    delete shape;
  }
  shapes.clear();
}

int main() {
  std::vector<Figure*> shapes = inputShapes();
  printAreasAndPerimeters(shapes);
  deleteShapes(shapes);
  return 0;
}
