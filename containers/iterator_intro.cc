#include <deque>
#include <iostream>

int main() {
  std::deque<int> a = {1, 2, 3};

  auto i = std::begin(a);

  std::cout << *i << std::endl;
  std::cout << *(i + 2) << std::endl;

  ++i;
  std::cout << *(i - 1) << std::endl;

  --i;
  std::cout << std::boolalpha << (i == std::end(a)) << std::endl;

  i += 3;
  std::cout << std::boolalpha << (i == std::end(a)) << std::endl;
}
