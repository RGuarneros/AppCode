
#include <iostream>
#include <cmath>
#include <cmath>
#include <functional>
//#include "cxxopts.hpp"

using namespace std;

double newton_root(function< double(double) > f, function< double(double) > fprime) {
    double x{ 1. };
    while (true) {
        auto fx = f(x);
        /*  cout << "f( " << x << " ) = " << fx << '\n';*/
        if (abs(fx) < 1.e-10) break;
        x = x - fx / fprime(x);
    }
    return x;
};

double newton_root(function< double(double) > f) {
    double x{ 1.0 };
    double h = 1e-6;
    while (true) {
        auto fx = f(x);

        /*  cout << "f( " << x << " ) = " << fx << '\n';*/
        if (abs(fx) < 1.e-10) break;
        function<double(double)> fprime = [h, f](double x) {return ((f(x + h) - f(x)) / h); };
        x = x - fx / (fprime(x));
    }
    return x;
};

int main() {

    /*cxxopts::Options options
    ("cxxopts",
        "Commandline options demo");
    options.add_options()
        ("h,help", "usage information")
        ;*/

    /*auto result = options.parse(argc, argv);
    if (result.count("help") > 0) {
        cout << options.help() << '\n';
        return 0;
    }

    cout << "The application starts here\n";
    return 0;*/

    for (double n = 2; n <= 8; ++n)
    {
        cout << "sqrt(" << n << ")=";

        auto f = [n](double x) { return (x * x) - n; };


        double result = newton_root(f);
        cout << result << endl;
    }


    return 0;
}