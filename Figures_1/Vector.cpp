#include <algorithm>
#include <cassert>
#include <iostream>

class Vector {
  double* data;
  int size;
  bool in_use = false;
  bool is_owner = false;
 public:
  Vector(int size) : size(size) { data = new double[size]; }
  Vector(const Vector& other)
      : data(other.data), size(other.size), is_owner(false), in_use(false) {}
  Vector& operator=(const Vector& other) {
    if (this != &other) {
      if (is_owner && data) {
        delete[] data;
      }
      data = other.data;
      size = other.size;
      is_owner = false;
      in_use = false;
    }
    return *this;
  }
  Vector Subvector(int offset, int subsize) {
    assert(offset >= 0 && subsize >= 0 && offset + subsize <= size);
    Vector sub(0);
    sub.data = data + offset;
    sub.size = subsize;
    sub.is_owner = false;
    sub.in_use = false;
    return sub;
  }
  const double operator[](int index) const { return data[index]; }
  double& operator[](int index) {
    if (!is_owner) {
      double* new_data = new double[size];
      std::copy(data, data + size, new_data);
      data = new_data;
      is_owner = true;
    }
    return data[index];
  }
  double* AquireBuffer() {
    assert(!in_use);
    in_use = true;
    return data;
  }
  void ReleaseBuffer() { in_use = false; }
  ~Vector() {
    if (is_owner) {
      delete[] data; // начальный вектор изначально owner,
    }  // если его изменяют или удаляют, то его подвекторы тоже так же меняются
  }
};

int main() {
  Vector a(5);
  a[1] = 10;
  std::cout << a[1] << '\n';
  Vector b = a;
  b[1] = 100;
  std::cout << a[1] << '\n';
  std::cout << b[1] << '\n';
  Vector c = a.Subvector(1, 3);
  std::cout << c[0] << '\n';  
}
