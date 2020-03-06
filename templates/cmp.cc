#include <iostream>

// This example demonstrates that we need a function object, then
// defaulted, to get a default comparison function.

// This function will be optimzed out, sometimes at compile time - it
// will not be even called.

// Even if we call it like this, the function will be optimized out
// anyway:
//
// int i = 1, j = 2;
// compare(i, j);

template <typename T, typename F = std::less<T>>
bool
compare(const T &a, const T &b, F f = {})
{
  return f(a, b);
}

int
main()
{
  volatile int i = 1, j = 2;
  std::cout << std::boolalpha << compare(1, 2) << std::endl;
  std::cout << std::boolalpha << compare(i, j) << std::endl;
}
