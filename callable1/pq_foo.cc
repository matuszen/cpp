#include <iostream>
#include <queue>

bool foo(const int &a, const int &b) { return a > b; }

int main(void) {
  std::priority_queue<int, std::vector<int>, bool (*)(const int &, const int &)>
      q(foo);

  q.push(2);
  q.push(1);
  q.push(3);

  while (!q.empty()) {
    std::cout << q.top() << std::endl;
    q.pop();
  }

  return 0;
}
