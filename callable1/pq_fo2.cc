#include <iostream>
#include <queue>

struct CMP {
  bool m_order;

  CMP(bool order) : m_order(order) {}

  bool operator()(const int &a, const int &b) const {
    return m_order ? a < b : a > b;
  }
};

int main(void) {
  bool order;

  std::cout << "Enter 0 or 1:";
  std::cin >> order;

  std::priority_queue<int, std::vector<int>, CMP> q(CMP{order});
  // The same as above.
  // priority_queue<int, vector<int>, CMP> q(order);

  q.push(2);
  q.push(1);
  q.push(3);

  while (!q.empty()) {
    std::cout << q.top() << std::endl;
    q.pop();
  }

  return 0;
}
