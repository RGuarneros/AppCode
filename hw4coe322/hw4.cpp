#include <iostream>

using std::cout;








int main (){
  
  cin >> nprimes;
  primegenerator sequence;
  while (sequence.number_of_primes_found()<nprimes) {
    int number = sequence.nextprime();
    cout << "Number " << number << " is prime" << '\n';
    
  }


  return 0;
}
