#include <iostream>
#include <queue>
#include <vector>

struct CMP {
  bool operator()(const int &a, const int &b) { return a > b; }
};

int main(void) {
  // An object of CMP will be default-constructed by q.
  std::priority_queue<int, std::vector<int>, CMP> q;

  q.push(2);
  q.push(1);
  q.push(3);

  while (!q.empty()) {
    std::cout << q.top() << std::endl;
    q.pop();
  }

  return 0;
}
