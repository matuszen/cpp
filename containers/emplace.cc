#include <forward_list>
#include <iostream>
#include <list>
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
};

int main() {
  std::cout << "vector: -----------------------------------------\n";

  {
    std::vector<A> v;

    // Uncommend the line below to prevent vector reallocation.
    // v.reserve(3);

    auto i1 = v.begin();

    // This becomes the first element in the vector.
    std::cout << "Checkpoint V1\n";
    v.emplace_back("V1");
    std::cout << "Checkpoint V2\n";
    v.emplace(v.begin(), "V2");
    std::cout << "Checkpoint V3\n";
    v.emplace(v.end(), "V3");

    std::cout << "The vector elements are:\n";
    for (const auto &e : v)
      std::cout << e.m_id << std::endl;

    std::cout << "The vector was relocated: " << std::boolalpha
              << (i1 != v.begin()) << std::endl;
  }

  std::cout << "list: -------------------------------------------\n";

  {
    std::list<A> l;
    // We can emplace at the front, and at the back, because the list
    // is doubly-linked.
    l.emplace_front("L1");
    l.emplace_back("L2");
    l.emplace(++(l.begin()), "L3");

    std::cout << "The list elements are:\n";
    for (const auto &e : l)
      std::cout << e.m_id << std::endl;
  }

  std::cout << "forward_list: -----------------------------------\n";

  {
    std::forward_list<A> f;
    f.emplace_front("L1");
    // We can emplace after an element, but not before, because it's a
    // singly-linked list.
    f.emplace_after(f.begin(), "L2");

    // We can't emplace at the back, because we don't have an iterator
    // to the preceeding element in the list.

    // f.emplace_back("L3");

    std::cout << "The forward_list elements are:\n";
    for (const auto &e : f)
      std::cout << e.m_id << std::endl;
  }

  return 0;
}
