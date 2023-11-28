/* NOTE
 * first "module load gcc/11"
 * and   "module load rangev3"
 * then compile this with
 * g++ -I${TACC_RANGEV3_INC} filter.cpp
 */

#include <iostream>
using std::boolalpha;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::any_of;
// #include <ranges>
// NOTE
#include <range/v3/all.hpp>

#include <cmath>

int main() {
  //want infinite generator of numbers to find perfect nums (iota), start at 2
  //Inside that we need another generator of numbers that goes up to 
  // the number right before the number youre testing(iota)
  // Then you want to check which numbers are divisors of the number youre
  // testing starting at 2.
  // Initialize summation to 1 since every number has 1 as a divisor

  auto perfect_nums = ranges::views::iota(2);
  auto divisor_seq = perfect_nums;
  //for (auto i:perfect_range){cout << i << '\n';}; // CHECK THAT ITS INFINITE LOOP
  
  auto prev_nums = perfect_nums | 
    ranges::views::filter([divisor_seq] 
    (auto i) -> bool {return i<divisor_seq;});
  
  for (auto n : prev_nums){cout << n << '\n';

#if 0
    auto divisors = perfect_num | ranges::views::filter
    ([perfect_num] (int divisor) -> bool{
      return perfect_num%divisor==0;});
  for (auto i:divisors){cout << i <<'\n';};
#endif 
  return 0;
}
