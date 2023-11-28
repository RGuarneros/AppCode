#include <iostream>
#include <vector>
#include <algorithm>
#include <range/v3/all.hpp>

using std::boolalpha;
using std::cout;

int main() {
  auto perfect_nums = ranges::views::iota(2) | ranges::views::filter([](int n){
      auto divisors_sum = ranges::accumulate(
					     ranges::views::iota(1, n) | ranges::views::filter([n](int i) { return n % i == 0; }),
					     0);
      return divisors_sum == n;
  });
  int count=0;
  for (auto n : perfect_nums) {
    cout << n << '\n';
    count++;
    if (count == 4){
      break;
    }
  }

  return 0;
}
