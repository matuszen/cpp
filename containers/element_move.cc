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

  A(const A &a) = delete;
  A &operator=(const A &a) = delete;

  A(A &&a) : m_id(std::move(a.m_id)) {
    m_id += "-moved";
    std::cout << "move-ctor: " << m_id << '\n';
  }

  A &operator=(A &&a) {
    m_id = std::move(a.m_id) + "-moved";
    std::cout << "move-assignment: " << m_id << '\n';
    return *this;
  }

  bool operator<(const A &a) const { return m_id < a.m_id; }
};

int main() {
  std::vector<A> v;
  std::cout << "Vector push_back:\n";
  v.push_back(A("V1"));
  std::cout << "Vector insert:\n";
  v.insert(v.begin(), A("V2"));
  std::cout << "Vector element assignment:\n";
  A a = std::move(v[0]);

  std::cout << "-------------------------------------------------\n";

  std::list<A> l;
  std::cout << "List push_back:\n";
  l.push_back(A("L1"));
  std::cout << "List push_front:\n";
  l.push_front(A("L2"));
  std::cout << "List element assignment:\n";
  (*l.begin()) = std::move(a);

  std::cout << "-------------------------------------------------\n";

  std::set<A> s;
  std::cout << "Set insert:\n";
  s.insert(A("S2"));
  std::cout << "Set insert again:\n";
  s.insert(A("S1"));

  std::cout << "-------------------------------------------------\n";

  return 0;
}
