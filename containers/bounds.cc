#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> v = {"a", "ab", "ba", "abc"};

  // This functor sorts by the size of the string only.  Strings of
  // equal size are incomparable.  Incomparable are "ab" and "ba".
  auto c = [](const std::string &a, const std::string &b) {
    return a.size() < b.size();
  };

  // Points to the first element such that c(element, "aa") is not
  // true, and this is "ab" in v.
  auto lb = lower_bound(v.begin(), v.end(), "aa", c);
  assert(*lb == "ab");

  // Points to the first element such that c("aa", element) is true,
  // and this is "abc" in v.
  auto ub = upper_bound(v.begin(), v.end(), "aa", c);
  assert(*ub == "abc");
}
