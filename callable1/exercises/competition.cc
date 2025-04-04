#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using places_type = std::map<std::string, int>;

struct cmp {
  places_type &m_places;

  cmp(places_type &places) : m_places(places) {}

  bool operator()(const std::string &a, const std::string &b) const {
    return m_places[a] < m_places[b];
  }
};

int main() {
  std::vector<std::string> v = {"Mo", "Ann", "Joe"};

  places_type places = {{"Mo", 3}, {"Ann", 1}, {"Joe", 2}, {"Shmo", 4}};

  sort(v.begin(), v.end(), cmp(places));

  for (auto &name : v) {
    std::cout << name << std::endl;
  }

  std::sort(v.begin(), v.end(),
            [&places](const std::string &a, const std::string &b) {
              return places[a] < places[b];
            });

  // The same as above.
  std::sort(v.begin(), v.end(),
            [&places](auto &a, auto &b) { return places[a] < places[b]; });

  return 0;
}
