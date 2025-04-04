#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector v{3, 1, 2};
  std::sort(v.begin(), v.end());

  for (const auto &e : v) {
    std::cout << e << std::endl;
  }

  return 0;
}
