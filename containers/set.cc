#include <iostream>
#include <set>

int main() {
  // A compiler can deduce the type of the elements stored in the set.
  // Equivalent to: set<int> s = {3, 1, 2};
  std::set s = {3, 1, 2};

  for (auto &e : s) {
    std::cout << e << std::endl;
  }

  // This would not compile, because we cannot modify the elements.
  // for(auto &e: s)
  //   cout << ++e << endl;

  std::multiset ms = {1, 2, 3, 1, 2, 3};

  for (auto &e : ms) {
    std::cout << e << std::endl;
  }
}
