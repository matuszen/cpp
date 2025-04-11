#include <deque>
#include <forward_list>
#include <iostream>

int main() {
  std::forward_list<int> a = {1, 2, 3};

  auto i = std::begin(a);

  std::cout << *i << std::endl;

  // That would not compile.
  // cout << *(i + 2) << endl;

  ++i;

  // That would not compile.
  // cout << *(i - 1) << endl;

  // That would not compile.
  // --i;

  std::cout << std::boolalpha << (i == std::end(a)) << std::endl;

  // That would not compile.
  // i += 3;

  std::cout << std::boolalpha << (i == std::end(a)) << std::endl;
}
