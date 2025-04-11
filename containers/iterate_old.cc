#include <iostream>
#include <utility>
#include <vector>

int main() {
  std::vector v = {1, 2, 3};

  // The legacy way of iterating.  We can modify the elements, because
  // we're using a non-const iterator.
  for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    std::cout << (*i)++ << std::endl;

  // That would not compile, because we're trying to modifying the
  // elements that we access through a const iterator.
  // for(std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
  //   std::cout << (*i)++ << std::endl;

  // We can use the 'auto' type -- the preferred way, because it's
  // less error-prone.  We let the compiler deduce the iterator type.
  for (auto i = v.begin(); i != v.end(); ++i)
    std::cout << (*i)++ << std::endl;

  // We're using const iterators here.
  for (auto i = v.cbegin(); i != v.cend(); ++i)
    std::cout << *i << std::endl;

  // We're using const iterators here as well.
  for (auto i = std::begin(std::as_const(v)); i != end(std::as_const(v)); ++i)
    std::cout << *i << std::endl;

  return 0;
}
