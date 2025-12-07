#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <memory>
#include <cmath>
#include <algorithm>
#include <stdexcept>

class Operation {
public:
  virtual ~Operation() = default;
  virtual int arity() const = 0;
  virtual double execute(const std::vector<double>& args) const = 0;
};

class UnaryOperation : public Operation {
public:
  int arity() const override { return 1; }
};

class BinaryOperation : public Operation {
public:
  int arity() const override { return 2; }
};

class TernaryOperation : public Operation {
public:
  int arity() const override { return 3; }
};

class Sin : public UnaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    return std::sin(args[0]);
  }
};

class Cos : public UnaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    return std::cos(args[0]);
  }
};

class Tg : public UnaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    double cos_val = std::cos(args[0]);
    if (cos_val == 0.0) {
      throw std::runtime_error("Tangent cannot be calculated");
    }
    return std::sin(args[0]) / cos_val;
  }
};

class Ctg : public UnaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    double sin_val = std::sin(args[0]);
    if (sin_val == 0.0) {
      throw std::runtime_error("Cotangent cannot be calculated");
    }
    return std::cos(args[0]) / sin_val;
  }
};

class Exp : public UnaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    return std::exp(args[0]);
  }
};

class Log : public UnaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    if (args[0] <= 0.0) {
      throw std::runtime_error("Logarithm cannot be calculated");
    }
    return std::log(args[0]);
  }
};

class Sqrt : public UnaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    if (args[0] < 0.0) {
      throw std::runtime_error("Square cannot be calculated");
    }
    return std::sqrt(args[0]);
  }
};

class Plus : public BinaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    return args[0] + args[1];
  }
};

class Minus : public BinaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    return args[0] - args[1];
  }
};

class Multiply : public BinaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    return args[0] * args[1];
  }
};

class Divide : public BinaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    if (args[1] == 0.0) {
      throw std::runtime_error("Division cannot be calculated");
    }
    return args[0] / args[1];
  }
};

class Atan2 : public BinaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    return std::atan2(args[0], args[1]);
  }
};

class Pow : public BinaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    return std::pow(args[0], args[1]);
  }
};

class Median : public TernaryOperation {
public:
  double execute(const std::vector<double>& args) const override {
    double a = args[0];
    double b = args[1];
    double c = args[2];
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);
    return b;
  }
};

class Calculator {
private:
  std::map<std::string, std::unique_ptr<Operation>> operations;
  std::vector<double> stack;

  void initializeOperations() {
    operations["sin"] = std::make_unique<Sin>();
    operations["cos"] = std::make_unique<Cos>();
    operations["tg"] = std::make_unique<Tg>();
    operations["ctg"] = std::make_unique<Ctg>();
    operations["exp"] = std::make_unique<Exp>();
    operations["log"] = std::make_unique<Log>();
    operations["sqrt"] = std::make_unique<Sqrt>();
    operations["+"] = std::make_unique<Plus>();
    operations["-"] = std::make_unique<Minus>();
    operations["*"] = std::make_unique<Multiply>();
    operations["/"] = std::make_unique<Divide>();
    operations["atan2"] = std::make_unique<Atan2>();
    operations["pow"] = std::make_unique<Pow>();
    operations["median"] = std::make_unique<Median>();
  }

  bool isNumber(const std::string& token) {
    std::istringstream iss(token);
    double value;
    iss >> value;
    return !iss.fail() && iss.eof();
  }

  void processToken(const std::string& token) {
    if (isNumber(token)) {
      double value;
      std::istringstream(token) >> value;
      stack.push_back(value);
    } else {
      auto it = operations.find(token);
      if (it == operations.end()) {
        throw std::runtime_error("Unknown operation: " + token);
      }

      Operation* op = it->second.get();
      if (stack.size() < static_cast<size_t>(op->arity())) {
        throw std::runtime_error("Not enough operands for operation " + token);
      }

      std::vector<double> args(op->arity());
      for (int i = op->arity() - 1; i >= 0; --i) {
        args[i] = stack.back();
        stack.pop_back();
      }

      double result = op->execute(args);
      stack.push_back(result);
    }
  }

public:
  Calculator() {
    initializeOperations();
  }

  double evaluate(const std::string& expression) {
    stack.clear();
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
      processToken(token);
    }

    if (stack.empty()) {
      throw std::runtime_error("Empty expression");
    }
    if (stack.size() != 1) {
      throw std::runtime_error("Too many operands");
    }
    return stack[0];
  }
};

int main() {
  Calculator calculator;
  std::string s;
  std::getline(std::cin, s);
  try {
    double result = calculator.evaluate(s);
    std::cout << "Result: " << result << "\n";
  }
  catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << "\n";
    return 1;
  }
  return 0;
}