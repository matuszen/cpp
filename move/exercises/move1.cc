#include <string>
#include <utility>

struct A {
  A() = default;
  A(const A &) = default;
  A &operator=(const A &) = default;
  ~A() = default;
};

struct B : public A {
  std::string m_txt;

  B(const std::string &txt) : m_txt(txt) {}

  B(B &&other) noexcept : A(std::move(other)), m_txt(std::move(other.m_txt)) {}

  B &operator=(B &&other) noexcept {
    if (this != &other) {
      A::operator=(std::move(other));
      m_txt = std::move(other.m_txt);
    }
    return *this;
  }

  B(const B &) = delete;
  B &operator=(const B &) = delete;
};

int main() {
  B b1("Hello");
  B b2 = std::move(b1);
}
