#include <deque>
#include <iostream>
#include <list>

int main() {
  std::list<int> a = {1, 2, 3};

  auto i = std::begin(a);

  std::cout << *i << std::endl;

  // That would not compile.
  // cout << *(i + 2) << endl;

  ++i;

  // That would not compile.
  // cout << *(i - 1) << endl;

  --i;

  std::cout << std::boolalpha << (i == std::end(a)) << std::endl;

  // That would not compile.
  // i += 3;

  std::cout << std::boolalpha << (i == std::end(a)) << std::endl;

  return 0;
}
