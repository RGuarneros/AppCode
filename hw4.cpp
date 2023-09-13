//Nathaniel Beasley ntb936 natbea
//Richard Guarneros rg47499 guarneros
//Jeremiah Do jkd2296 jeremiahkdo


#include <iostream>
using namespace std;

//prime checker
bool isprime(int n) {
    bool primeness = true;
    for (int factor = 2; factor <= n / 2; factor++) {
        if (n % factor == 0) {
            primeness = false; break;
        }
    }
    return primeness;
}
//create primegenerator
class primegenerator {
private:
    //initialize before constructor
    int index {0};
    //don't check 0
    int lastprime {1};

public:
    //counter
    int number_of_primes_found() {
        return index;
    }
    //iterating from current prime to next
    int nextprime() {
        //move to next number, skipping in between non primes
        lastprime++;
        //while the number isn't prime, we move on
        while (!isprime(lastprime)) {
            lastprime++;
        }
        //if we find a prime, add to index
        index++;
        //output prime if found
        return lastprime;
       
    }
};

int main() {
    int nprimes;
    cin >> nprimes;
    primegenerator sequence;

    while (sequence.number_of_primes_found() < nprimes) {
        int number = sequence.nextprime();
        cout << "Number " << number << " is prime" << '\n';
    }

    return 0;
}

