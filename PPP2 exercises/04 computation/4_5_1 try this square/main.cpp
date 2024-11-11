#include <iostream>
using std::cout, std::cin, std::endl;

long square(long x);

int main() {
    cout << "Enter a number: ";
    long x;
    cin >> x;
    cout << square(x);
}

long square(long x)
{
    // Handles negative numbers for squares but not for other powers
    long result = 0;
    x = abs(x);
    for (int i = 0; i < x; ++i)
    {
        result += x;
    }
    return result;
}