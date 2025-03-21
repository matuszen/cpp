#include <iostream>

struct A {};

void operator++(A &a) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

void operator++(A &&a) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

int main() {
  A a;
  ++a;
  ++A();
}
