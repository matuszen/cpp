#include <iostream>
#include <iterator>
#include <utility>

int main() {
  int a[] = {1, 2, 3};

  // The old way of iterating.  We can modify the elements, because
  // we're using a pointer to non-const data.
  for (int *i = std::begin(a); i != std::end(a); ++i)
    std::cout << (*i)++ << std::endl;

  // That would not compile, because we're trying to modifying the
  // elements that we access through a pointer to the const data.
  // for(const int *i = std::begin(a); i != std::end(a); ++i)
  //   std::cout << (*i)++ << std::endl;

  // We can use the 'auto' type -- the preferred way, because it's
  // less error-prone.  We let the compiler deduce the iterator type.
  for (auto i = std::begin(a); i != std::end(a); ++i)
    std::cout << (*i)++ << std::endl;

  // We're using a const iterator (a pointer to const data) here.
  for (auto i = std::cbegin(a); i != std::cend(a); ++i)
    std::cout << *i << std::endl;

  // We're using const iterators here.
  for (auto i = std::begin(std::as_const(a)); i != std::end(std::as_const(a));
       ++i)
    std::cout << *i << std::endl;

  return 0;
}
