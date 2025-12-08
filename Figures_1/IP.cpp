#include <iostream>

class IpAdress {
  int adress[4];
 public:
  IpAdress() = default;
  IpAdress(int c1, int c2, int c3, int c4) {
    adress[0] = c1;
    adress[1] = c2;
    adress[2] = c3;
    adress[3] = c4;
  }
  friend std::ostream& operator<<(std::ostream& s, const IpAdress& cur) {
    for (int i = 0; i < 4; ++i) {
      s << cur.adress[i];
      if (i != 3) {
        s << '.';
      }
    }
  return s;
  }
  friend std::istream& operator>>(std::istream& s, IpAdress& cur) {
    char dot = '.';
    for (int i = 0; i < 4; ++i) {
      s >> cur.adress[i];
      if (i != 3) {
        s >> dot;
      }
    }
    return s;
  }
  bool operator==(const IpAdress& other) {
    return adress[0] == other.adress[0] && adress[1] == other.adress[1] &&
           adress[2] == other.adress[2] && adress[3] == other.adress[3];
  }
  bool operator!=(const IpAdress& other) { return !((*this) == other);
  }
  IpAdress& operator++() {
    for (int i = 3; i >= 0; --i) {
      if (adress[i] < 255) {
        ++adress[i];
        break;
      } else {
        adress[i] = 0;
      }
    }
    return *this;
  }
};

int main() {
  /*IpAdress ip = IpAdress(1,23,3,128);
  std::cout << ip << '\n';
  IpAdress ip1 = IpAdress();
  std::cin >> ip1;
  std::cout << ip1;*/

  IpAdress start; // работает только если start <= finish
  IpAdress finish;
  std::cin >> start >> finish;
  std::cout << start << '\n';
  while (start != finish) {
    ++start;
    std::cout << start << '\n';
  }
}
