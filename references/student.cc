#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <utility>

struct student {
  unsigned m_age;
  std::string m_fn;
  std::string m_ln;

  student(unsigned age, std::string fn, std::string ln)
      : m_age(age), m_fn(std::move(fn)), m_ln(std::move(ln)) {}

  bool operator<(const student &a) const {
    // Function std::tie returns a tuple of const references.  We use
    // the < operator defined for a tuple, which compares
    // lexicographically.  There is no overhead of std::tie, because
    // it's optimized out.
    return tie(m_age, m_fn, m_ln) < tie(a.m_age, a.m_fn, a.m_ln);
  }
};

std::ostream &operator<<(std::ostream &out, const student &a) {
  out << "(" << a.m_age << ", " << a.m_fn << ", " << a.m_ln << ")";
  return out;
}

int main() {
  std::set<student> s;
  s.emplace(19, "Betty", "O'Barley");
  s.emplace(20, "Harry", "O'Hay");
  s.emplace(20, "Harry", "Potter");
  for (const auto &e : s)
    std::cout << e << std::endl;
}
