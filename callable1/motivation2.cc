#include <algorithm>
#include <iostream>
#include <vector>

struct A {
  int id;
  A(int id) : id(id) {}

  bool operator<(const A &a) const { return this->id < a.id; }
};

int main() {
  std::vector v{A(3), A(1), A(2)};
  std::sort(v.begin(), v.end());

  for (const auto &e : v) {
    std::cout << e.id << std::endl;
  }

  return 0;
}
