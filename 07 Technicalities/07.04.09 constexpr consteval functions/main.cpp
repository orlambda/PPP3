#include "../../PPP_support/PPPheaders.h"

constexpr double half1(double d) { return d/2; }
consteval double half2(double d) { return d/2; } // can only be evaluated at compile time

int main() {
    // consteval double x1 = half2(7); // Error: consteval can only be used for function declarations
    double x1 = half2(7); // OK: 7 is a constant
    constexpr double x2 = half2(7); // As above but evaluated at compile time
    // double x3 = half2(x1); // error: x1 is a non-const variable
    double x3 = half1(x1); // OK:
        // half1 (constexpr) behaves as a normal function until const is needed
        // so x1 can be a non-const variable
    constexpr double x5 = half2(x2); // OK: x2 is calculated at compile time
}
