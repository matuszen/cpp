#include <iostream>
#include <queue>
#include <vector>

int main() {
  bool order;

  std::cout << "Enter 0 or 1: ";
  std::cin >> order;

  auto c = [order](const int &a, const int &b) {
    return order ? a < b : a > b;
  };

  std::priority_queue<int, std::vector<int>, decltype(c)> q(c);

  q.push(2);
  q.push(1);
  q.push(3);

  while (!q.empty()) {
    std::cout << q.top() << std::endl;
    q.pop();
  }

  return 0;
}
