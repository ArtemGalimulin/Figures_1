#include <iostream>
#include <vector>
#include <stdexcept>
class IP {
  std::vector<int> ip;
public:
  IP(std::vector<int> a = { 0, 0, 0, 0 }) {
    ip = a;
  }
  void input() {
    int a1, a2, a3, a4;
    std::cin >> a1 >> a2 >> a3 >> a4;
    std::vector<int> a = { a1, a2, a3, a4 };
    for (int i = 0; i < 4; i++) {
      if ((a[i] < 0) or (a[i] > 255)) {
        throw std::invalid_argument("Ёлемент IP должен быть числом от 0 до 255");
      }
    }
    ip = a;
  }
  void print() const {
    std::cout << ip[0] << '.' << ip[1] << '.' << ip[2] << '.' << ip[3] << '\n';
  }
  std::vector<int> value() const {
    return ip;
  }
  bool operator<=(const IP& other) const {
    return value() <= other.value();
  }
  bool operator!=(const IP& other) const {
    return value() != other.value();
  }
  IP& operator++() {
    for (int i = 3; i >= 0; i--) {
      if (ip[i] < 255) {
        ip[i]++;
        break;
      }
      else {
        ip[i] = 0;
      }
    }
    return *this;
  }
};
void print_ip_range(const IP& a, const IP& b) {
  IP ip1 = a;
  IP ip2 = b;
  if (ip1 <= ip2) {
    while (ip1 != ip2) {
      ip1.print();
      ++ip1;
    }
    ip2.print();
  }
  else {
    while (ip1 != ip2) {
      ip2.print();
      ++ip2;
    }
    ip1.print();
  }
}
int main() {
  IP ip1, ip2;
  ip1.input();
  ip2.input();
  print_ip_range(ip1, ip2);
  return 0;
}