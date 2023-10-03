// Richard Guarneros rg47499
// Jeremiah Do jkd2296
// Nathaniel Beasley ntb936

#include <iostream>
#include <cmath>
#include <functional>
#include <string>

#include "fmt/format.h"

using namespace std;
using fmt::format;
using fmt::print;

int main (){

    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            //output 16*i+j on base 16(hexadecimal)
            print("{0:02x} ",16*i+j,2);
        }
        cout << "\n";
    }

    return 0;
}
