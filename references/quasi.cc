#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

// This example demonstrates that, unlike containers, std::pair and
// std::tuple can have elements of a reference type.  std::pair,
// std::tuple, and std::array are quasi-containers, because they have
// some container functionality, but cannot change size at run-time as
// containers do.
int main() {
  // Error: the pair elements of reference type must be initialized.
  // std::pair<int &, int &> p2;

  int x = 1;

  std::pair<int &, int &> p(x, x);
  p.second = 2;

  std::cout << "x = " << x << std::endl;

  // The tuple elements of reference type must be initialized.
  std::tuple<int &, int &, int &> t(x, x, x);
  std::get<2>(t) = 3;

  std::cout << "x = " << x << std::endl;

  // Interestingly, we cannot have a vector of references, but we can
  // have a vector of reference pairs.
  std::vector<std::pair<int &, int &>> v{p, p};
  v[1].second = 4;

  std::cout << "v[0].first = " << v[0].first << std::endl;
  std::cout << "x = " << x << std::endl;
}
