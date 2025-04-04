#include <iostream>
#include <queue>
#include <vector>

int main() {
  // HERE'S THE DIFFERENCE!
  std::priority_queue<int, std::vector<int>, std::greater<int>> q;

  // I was hoping the third template argument would be deduced from
  // the constructor argument, but, alas, not.
  // priority_queue<int> q(std::greater<int>{});

  q.push(2);
  q.push(1);
  q.push(3);

  while (!q.empty()) {
    std::cout << q.top() << std::endl;
    q.pop();
  }

  return 0;
}
