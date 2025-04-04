#include <iostream>
#include <queue>

int main() {
  std::priority_queue<int> q;

  q.push(2);
  q.push(1);
  q.push(3);

  while (!q.empty()) {
    std::cout << q.top() << std::endl;
    q.pop();
  }

  return 0;
}
