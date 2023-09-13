// Names:
//   Richard Guarneros
//   Nathaniel Beasley
//   Jeremiah Do

#include <iostream>
using namespace std;

class primegenerator {
private:
  int last_result{ 0 };
public:
  int number_of_primes_found() {

  };
  int nextprime() {

  };
};


int main() {
  int nprimes;
  cin >> nprimes;
  primegenerator sequence;
  while (sequence.number_of_primes_found() > nprimes) {
    int number = sequence.nextprime();
    cout << "Number " << number << " is prime" << '\n';
  }
  return 0;
}
