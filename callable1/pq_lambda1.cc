#include <iostream>
#include <queue>
#include <vector>

int main() {
  auto f = [](const int &a, const int &b) { return a > b; };

  std::priority_queue<int, std::vector<int>, decltype(f)> q(f);

  q.push(2);
  q.push(1);
  q.push(3);

  while (!q.empty()) {
    std::cout << q.top() << std::endl;
    q.pop();
  }

  return 0;
}
