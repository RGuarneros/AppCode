#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"
#include <iostream>
#include <vector>
#include <cmath>

class Polynomial {
public:
    Polynomial(const std::vector<double>& coefficients) : coefficients(coefficients) {}

    bool is_odd() const {
        return coefficients.size() > 0 && static_cast<int>(coefficients.size()) % 2 != 0;
    }

    double operator()(double x) const {
        double result = 0.0;
        double xn = 1.0;
        for (int i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * xn;
            xn *= x;
        }
        return result;
    }

private:
    std::vector<double> coefficients;
};

void find_initial_bounds(const Polynomial& poly, double& left, double& right) {
    if (!poly.is_odd()) {
        throw std::invalid_argument("Polynomial must be odd-degree for bisection method.");
    }

    const double step = 0.1;
    double x = left;
    double leftVal = poly(x);

    while (x <= right) {
        double rightVal = poly(x);

        if (leftVal * rightVal <= 0.0) {
            return; // Found bounds
        }

        leftVal = rightVal;
        x += step;
    }

    throw std::invalid_argument("No initial bounds found.");
}

void move_bounds_closer(const Polynomial& poly, double& left, double& right) {
    double leftValue = poly(left);
    double rightValue = poly(right);

    if (leftValue * rightValue >= 0.0) {
        throw std::invalid_argument("Bounds do not enclose a root.");
    }

    if (leftValue > 0) {
        left = (left + right) / 2.0;
    }
    else {
        right = (left + right) / 2.0;
    }
}

double find_zero(const Polynomial& poly, double prec) {
    if (!poly.is_odd()) {
        throw std::invalid_argument("Polynomial must be odd-degree for bisection method.");
    }

    double left = -1.0;  // Initial bounds
    double right = 1.0;  // Adjust bounds based on your polynomial's expected range

    while (std::abs(poly(left)) >= prec) {
        double middle = (left + right) / 2.0;
        if (poly(left) * poly(middle) < 0) {
            right = middle;
        }
        else {
            left = middle;
        }
    }

    return (left + right) / 2.0;
}

TEST_CASE("Proper test", "[2]") {
    std::vector<double> validCoefficients{ 3.0, 2.0, 0.0, 1.0 };
    Polynomial third(validCoefficients); // 3x^3 + 2x^2 + 1

    double left = 10.0, right = 11.0;
    REQUIRE_NOTHROW(find_initial_bounds(third, left, right));
    REQUIRE(left < right);

    double old_left = left, old_right = right;
    REQUIRE_NOTHROW(move_bounds_closer(third, left, right));

    double leftval = third(left);
    double rightval = third(right);
    REQUIRE(leftval * rightval <= 0);

    REQUIRE(((left == old_left && right < old_right) || (right == old_right && left > old_left)));
}

int main() {
    std::vector<double> coefficients{ 3.0, 2.0, 0.0, 1.0 };
    Polynomial third(coefficients); // 3x^3 + 2x^2 + 1

    try {
        double zero = find_zero(third, 1.e-8);
        double value = third(zero);
        std::cout << "Found root " << zero << " with value " << value << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
