#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

struct A {
  std::string m_id;

  A(std::string &&id) : m_id(std::move(id)) {
    std::cout << "ctor: " << m_id << '\n';
  }

  ~A() { std::cout << "dtor: " << m_id << '\n'; }

  A(const A &a) : m_id(a.m_id) {
    m_id += "-copied";
    std::cout << "copy-ctor: " << m_id << '\n';
  }

  A(A &&a) : m_id(std::move(a.m_id)) {
    m_id += "-moved";
    std::cout << "copy-ctor: " << m_id << '\n';
  }

  A &operator=(const A &a) = delete;
  A &operator=(A &&a) = delete;

  bool operator<(const A &a) const { return m_id < a.m_id; }
};

int main() {
  // A temporary object is not moved but copied because {A("V1")}
  // creates an std::initializer_list object that provides access to
  // its elements through a const reference.
  std::vector<A> va, vb{A("V1")};
  std::cout << "Moving a container touches no element.\n";
  va = std::move(vb);

  std::cout << "-------------------------------------------------\n";

  // A temporary object is not moved but copied.  I don't know why.
  std::list<A> la, lb{A("L1")};
  std::cout << "Moving a container touches no element.\n";
  la = std::move(lb);

  std::cout << "-------------------------------------------------\n";

  // A temporary object is not moved but copied.  I don't know why.
  std::set<A> sa, sb{A("S1")};
  std::cout << "Moving a container touches no element.\n";
  sa = std::move(sb);

  std::cout << "-------------------------------------------------\n";

  return 0;
}
