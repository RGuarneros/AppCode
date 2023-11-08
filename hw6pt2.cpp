// Jeremiah Do jkd2296
// Richard Guarneros rg47499
// Nathaniel Beasley ncb936

#include <iostream>
#include <cmath>
#include <cmath>
#include <functional>
#include "cxxopts.hpp"

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

int main(int argc,char **argv) {

  cxxopts::Options options
    ("cxxopts",
     "Commandline options demo");
  options.add_options()
    ("h,help","usage information")
    ("v,input","input number",
     cxxopts :: value <int>()->default_value("37"));

    auto result = options.parse(argc, argv);
    if (result.count("help") > 0) {
        cout << options.help() << '\n';
        return 0;
    }


    auto input_number = result["input"].as<int>();
    cout << "Find square root of: " << input_number << '\n';


    cout << "The application starts here\n";
    return 0;*/

      cout << "sqrt(" << input_number << ")=";

      auto f = [input_number](double x) { return (x * x) - input_number; };


        double result = newton_root(f);
        cout << result << endl;


    return 0;
}
