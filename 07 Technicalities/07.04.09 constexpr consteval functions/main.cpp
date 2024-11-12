#include "../../PPP_support/PPPheaders.h"

consteval double half(double d) { return d/2; } // can only be evaluated at compile time

int main() {
    // consteval double x1 = half(7); // Error: consteval can only be used for function declarations
    double x1 = half(7); // OK: 7 is a constant
    constexpr double x2 = half(7); // As above but evaluated at compile time
    // double x3 = half(x1); // error: x1 is a non-const variable
    constexpr double x4 = half(x2); // OK: x2 is calculated at compile time
}
