//Nathaniel Beasley ntb936 natbea
//Richard Guarneros rg47499 guarneros
//Jeremiah Do jkd2296 jeremiahkdo


#include <iostream>
using namespace std;

//prime checker
bool isprime(int n) {
    bool primeness = true;
    if (n <= 0){
        primeness = false;
    }
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
    int index{ 0 };
    //don't check 0
    int lastprime{ 1 };

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
        //output prime if found
        index++;
        return lastprime;
       
    }
    void restart() {
        lastprime = 1;
    }
};

class evengenerator {
private:
    int evennum = { 2 };
public:
    int nexteven() {
        return evennum = evennum + 2;
    }
};

int main() {
    int nprimes;
    cin >> nprimes;
    primegenerator sequence;
    int evennum = 4;
    while (evennum <= nprimes){
        int prime_p = sequence.nextprime();
        int q = evennum - prime_p;
        if (isprime(q)) {
            cout << prime_p << " + " << q << " = " << evennum << endl;
            sequence.restart();
        evennum = evennum + 2;
        }
    }
    return 0;
}

