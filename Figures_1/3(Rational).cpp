#include <iostream>
#include <cmath>

class Rational {
private:
  int m;
  int n;
  int gcd(int a, int b) const {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }
  void reduce() {
    if (n < 0) {
      m = -m;
      n = -n;
    }
    int k = gcd(m, n);
    m /= k;
    n /= k;
  }

public:
  Rational(int x = 0, int y = 1) : m(x), n(y) {
    reduce();
  }
  operator double() const {
    return static_cast<double>(m) / n;
  }
  Rational* operator+=(const Rational other) {
    m = n * other.m + m * other.n;
    n = n * other.n;
    reduce();
    return this;
  }
  Rational* operator-=(const Rational other) {
    m = -n * other.m + m * other.n;
    n = n * other.n;
    reduce();
    return this;
  }
  Rational* operator*=(const Rational other) {
    m = m * other.m;
    n = n * other.n;
    reduce();
    return this;
  }
  Rational* operator/=(const Rational other) {
    m = m * other.n;
    n = n * other.m;
    reduce();
    return this;
  }
  Rational operator++(int) {
    Rational temp = *this;
    m += n;
    reduce();
    return temp;
  }
  Rational operator--(int) {
    Rational temp = *this;
    m -= n;
    reduce();
    return temp;
  }
  Rational* operator++() {
    m = m + n;
    return this;
  }
  Rational* operator--() {
    m = m - n;
    return this;
  }
  Rational operator+(const Rational other) const {
    Rational sum = Rational(n * other.m + m * other.n, n * other.n);
    return sum;
  }
  Rational operator-(const Rational other) const {
    Rational dif = Rational(-n * other.m + m * other.n, n * other.n);
    return dif;
  }
  Rational operator*(const Rational other) const {
    Rational mul = Rational(m * other.m, n * other.n);
    return mul;
  }
  Rational operator/(const Rational other) const {
    Rational div = Rational(m * other.n, n * other.m);
    return div;
  }
  bool operator==(const Rational& other) const {
    return m == other.m && n == other.n;
  }
  bool operator!=(const Rational& other) const {
    return !(*this == other);
  }
  bool operator<(const Rational& other) const {
    return m * other.n < other.m * n;
  }
  bool operator>(const Rational& other) const {
    return other < *this;
  }
  bool operator<=(const Rational& other) const {
    return !(other < *this);
  }
  bool operator>=(const Rational& other) const {
    return !(*this < other);
  }
  void print() const {
    std::cout << m << '/' << n << '\n';
  }
};


int main() {
  Rational a(1, 3);
  Rational b(1, 6);
  std::cout << (bool)(a > b) << '\n';
  Rational sum = a + b;
  sum.print();
  return 0;
}