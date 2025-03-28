#include <iostream>
#include <string>
#include <utility>

struct A {
  int value;

  A(int v = 0) : value(v) {}
  A(const A &) = default;
  A &operator=(const A &) = default;
  A(A &&) noexcept = default;
  A &operator=(A &&) noexcept = default;

  virtual ~A() = default;
};

struct B : public A {
  std::string m_txt;

  B(int v, const std::string &txt) : A(v), m_txt(txt) {}

  B(const B &) = delete;
  B &operator=(const B &) = delete;

  B(B &&other) noexcept : A(std::move(other)), m_txt(other.m_txt) {}

  B &operator=(B &&other) noexcept {
    if (this != &other) {
      A::operator=(std::move(other));
      m_txt = other.m_txt;
    }
    return *this;
  }

  ~B() = default;
};

int main() {
  B b1(42, "Hello");
  B b2 = std::move(b1);

  std::cout << "b2 value: " << b2.value << ", b2 m_txt: " << b2.m_txt
            << std::endl;

  return 0;
}
