#include <iostream>
#include <utility>
#include <vector>

int main() {
  // The code works any range: a container and a C-style array.
  std::vector v = {1, 2, 3};
  // int v[] = {1, 2, 3};

  // We can modify the elements, because we use them through a
  // non-const reference of type: auto &
  for (auto &e : v)
    std::cout << ++e << std::endl;

  // Here we iterate with a const reference.
  for (const auto &e : v)
    std::cout << e << std::endl;

  // This would not compile, because we refer to the elements through
  // a const reference: const auto &

  // for(const auto &e: v)
  //   cout << ++e << endl;

  // We could also iterate through a non-const range and reference the
  // elements with a const reference, becasue we refer to the
  // non-const range with a const reference.
  for (auto &e : as_const(v))
    std::cout << e << std::endl;

  return 0;
}
