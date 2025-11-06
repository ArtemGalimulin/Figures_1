#include <iostream>
#include <cstdint>
class Vector {
  uint32_t size;
  double* buffer;
  bool isCopy, bufferOwners;
public:
  Vector(uint32_t n = 0) {
    if (n == 0) {
      buffer = nullptr;
    }
    else {
      buffer = new double[n];
    }
    size = 0;
    isCopy = false;
    bufferOwners = true;
  }
  Vector(Vector& other) {
    size = other.size;
    buffer = other.buffer;
    isCopy = true;
    bufferOwners = other.bufferOwners;
  }
  Vector(Vector& other, uint32_t i, uint32_t n) {
    size = n;
    buffer = other.buffer + i;
    isCopy = true;
    bufferOwners = other.bufferOwners;
  }
  double& operator[](uint32_t i) {
    if (not isCopy) {
      return buffer[i];
    }
    else {
      double* p = buffer;
      buffer = new double[size];
      isCopy = false;
      for (int i = 0; i < (int)size; i++) {
        buffer[i] = p[i];
      }
      return buffer[i];
    }
  }
  void operator=(Vector& other) {
    if (not bufferOwners) {
      if (not isCopy) {
        buffer = other.buffer;
        size = other.size;
        isCopy = other.isCopy;
        bufferOwners = other.bufferOwners;
      }
      else {
        double* p = buffer;
        buffer = new double[size];
        isCopy = false;
        for (int i = 0; i < (int)size; i++) {
          buffer[i] = other.buffer[i];
        }
      }
    }
    else {
      std::cout << "Эти данные нельзя изменить" << '\n';
    }
  }
  double* AquireBuffer() {
    bufferOwners = true;
    return buffer;
  }
  void ReleaseBuffer() {
    bufferOwners = false;
  }
};
int main() {
  Vector a(5);
  a[0] = 1; a[1] = 3; a[2] = 6; a[3] = 2; a[4] = 5;
  Vector b(a, 1, 3);
  std::cout << b[0] << " " << b[1] << " " << b[2] << '\n';
} 