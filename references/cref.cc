#include <string>
#include <iostream>

using namespace std;

// The function parameter is a const reference.
int foo(const string &) { return 0; }

int main() {
  // The data we bind references to.
  int x = 1;
  const int cx = 1;

  // The const reference binds to an lvalue.  The type of the
  // initializing expression `x` is automatically augmented with the
  // const qualifier.
  const int &l1 = x;

  std::cout << "l1: " << l1 << std::endl;

  // The reference to a const int is initialized with a const int.
  const int &cr = cx;

  std::cout << "cr: " << cr << std::endl;

  // Error: an lvalue reference cannot bind to an rvalue.
  // int &l2 = 1;
  // The const reference binds to an rvalue.
  const int &l3 = 1;

  std::cout << "l3: " << l3 << std::endl;

  // Expression "foo()" is an rvalue, because the function returns the
  // result by value.
  const int &c = foo("Hello!");
  std::cout << "c: " << c << std::endl;
  // Error: we cannot take the address of the returned value.
  // const int *p = &foo("Hello!");
  // But we can take the address to the temporary to which reference c
  // is bound.  The reference extends the lifetime of the temporary.
  const int *p = &c;
  std::cout << "p: " << *p << std::endl;

  string s;
  // The function parameter reference binds to an lvalue.
  foo(s);
  // Since C++98, a const reference can bind to the data of an rvalue.
  // Here the function parameter reference binds to an rvalue, which
  // is the expression with a temporary of type string created with
  // the constructor taking a "const char *".
  foo("Hello!");
}
