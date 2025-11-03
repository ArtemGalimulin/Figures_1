#include <iostream>
#include <stdexcept>

class Rational {
  long long numer;
  long long denom;
  static long long gcd(long long a, long long b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
      long long r = a % b;
      a = b;
      b = r;
    }
    return a ? a : 1;
  }
  void normalize() {
    if (denom == 0) throw std::invalid_argument("Zero denominator");
    if (denom < 0) {
      numer = -numer;
      denom = -denom;
    }
    if (numer == 0) {
      denom = 1;
      return;
    }
    long long factor = gcd(numer, denom);
    numer /= factor;
    denom /= factor;
  }

 public:
  Rational() : numer(0), denom(1) {}
  Rational(long long n, long long d) : numer(n), denom(d) {
    normalize();
  }
  operator double() const { return (double)numer / denom; }
  Rational& operator+=(const Rational& right) {
    numer = numer * right.denom + right.numer * denom;
    denom = denom * right.denom;
    normalize();
    return *this;
  }
  Rational& operator-=(const Rational& right) {
    numer = numer * right.denom - right.numer * denom;
    denom = denom * right.denom;
    normalize();
    return *this;
  }
  Rational& operator*=(const Rational& right) {
    numer *= right.numer;
    denom *= right.denom;
    normalize();
    return *this;
  }
  Rational& operator/=(const Rational& right) {
    if (right.numer == 0) {
      throw std::invalid_argument("Divide by zero");
    }
    numer *= right.denom;
    denom *= right.numer;
    normalize();
    return *this;
  }
  Rational& operator++() {
    numer += denom;
    normalize();
    return *this;
  }
  Rational& operator--() {
    numer -= denom;
    normalize();
    return *this;
  }
  Rational operator++(int) {
    Rational old = *this;
    ++(*this);
    return old;
  }
  Rational operator--(int) {
    Rational old = *this;
    --(*this);
    return old;
  }
  Rational operator+(const Rational& right) const {
    Rational tmp = *this;
    tmp += right;
    return tmp;
  }
  Rational operator-(const Rational& right) const {
    Rational tmp = *this;
    tmp -= right;
    return tmp;
  }
  Rational operator*(const Rational& right) const {
    Rational tmp = *this;
    tmp *= right;
    return tmp;
  }
  Rational operator/(const Rational& right) const {
    Rational tmp = *this;
    tmp /= right;
    return tmp;
  }
  bool operator==(const Rational& right) const {
    return numer == right.numer && denom == right.denom;
  }
  bool operator!=(const Rational& right) const { return !(*this == right); }
  bool operator<(const Rational& right) const {
    return numer * right.denom < right.numer * denom;
  }
  bool operator<=(const Rational& right) const {
    return numer * right.denom <= right.numer * denom;
  }
  bool operator>(const Rational& right) const {
    return numer * right.denom > right.numer * denom;
  }
  bool operator>=(const Rational& right) const {
    return numer * right.denom >= right.numer * denom;
  }
  friend std::ostream& operator<<(std::ostream& s, const Rational& cur) {
    s << cur.numer << '/' << cur.denom;
    return s;
  }
  friend std::istream& operator>>(std::istream& s, Rational& cur) {
    long long n = 0, d = 1;
    char slash = '/';
    s >> n >> slash >> d;
    cur = Rational(n, d);
    return s;
  }
};

int main() {
  Rational a, b;
  std::cin >> a >> b;
  std::cout << a + b << std::endl;
}
