#include <iostream>

struct A {
  volatile int &m_i;

  A(volatile int &i) : m_i(i) {}
};

int main() {
  volatile int i = 0;
  A a(i);
  a.m_i = 1;

  std::cout << "Value of i: " << i << std::endl;
  return 0;
}
