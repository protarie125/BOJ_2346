#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
deque<pair<ll, ll>> B;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  auto k = 1;
  while (0 < (n--)) {
    ll x;
    cin >> x;
    B.push_back({k++, x});
  }

  auto [r, now] = B.front();
  cout << r << ' ';
  B.pop_front();
  while (0 < B.size()) {
    if (0 < now) {
      while (1 < (now--)) {
        auto f = B.front();
        B.pop_front();
        B.push_back(f);
      }
      r = B.front().first;
      now = B.front().second;
      B.pop_front();
      cout << r << ' ';
    } else if (now < 0) {
      while ((now++) < 0) {
        auto b = B.back();
        B.pop_back();
        B.push_front(b);
      }
      r = B.front().first;
      now = B.front().second;
      B.pop_front();
      cout << r << ' ';
    }
  }

  return 0;
}