#include <cassert>
#include <iostream>

int &foo() {
  static int x = 1;
  return x;
}

int main() {
  int x = 1;

  // Can initialize an lvalue reference with an lvalue.
  int &xr = x;

  // Error: needs initialization.
  // int &a;

  // OK: foo() is an lvalue.
  int &fr = foo();

  // A const.
  const int c = 300000000;

  // Error: an lvalue reference cannot bind to a const.
  // int &r = c;

  // Error: an lvalue reference cannot bind to an rvalue.
  // int &ncr = 1;

  // Initialized alright.
  int &z = x, y = 2;

  // The same as above, but this time we know what "&" applies to.
  // int y = 2, &z = x;

  // This placement of "&" is confusing: does "&" apply to "y" too?
  // int& z = x, y = 2;

  // IMPORTANT: Now z is an alias of x.  Whenever you see z, just
  // replace it with x to understand the code below.

  // A reference has no address.  &z is the address of x.
  assert(&z == &x);

  // There's no "reinitialization"!  It's an assignment to x.
  z = y;
  // Now x has 2.
  std::cout << "x = " << x << std::endl;

  // Initialize an lvalue reference with an expression that z is an
  // alias of.  Expression z is simply treated as x.
  int &zz = z;
  // Therefore the above has the same effect as this one.
  int &zx = x;
}
