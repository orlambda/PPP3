#include <iostream>
using std::cin, std::cout, std::endl, std::sqrt;

// simple program to exercise operators
int main() {
    cout << "Please enter an integer: ";
    int n;
    cin >> n;
    cout
        << "n == " << n << endl
        << "n + 1 == " << n + 1 << endl
        << "three times n == " << n * 3 << endl
        << "twice n == " << n + n << endl
        << "n squared == " << n * n << endl
        << "half of n == " << n / 2 << endl
        << "square root of n == " << sqrt(n) << endl
        << "remainder of n divided by three == " << n % 3 << endl
        ;
    return 0;
}
