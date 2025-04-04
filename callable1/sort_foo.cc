#include <algorithm>
#include <iostream>
#include <vector>

bool cmp(const int &a, const int &b) { return a > b; }

int main() {
  std::vector v{3, 1, 2};
  std::sort(v.begin(), v.end(), cmp);

  for (const auto &e : v) {
    std::cout << e << std::endl;
  }

  return 0;
}
