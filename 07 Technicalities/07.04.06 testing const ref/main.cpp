#include "../../PPP_support/PPPheaders.h"

void increaseAll(int v, int& r, const int& cr);

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    // Error: f(1, 2, 3);
    increaseAll(a, b, c);
    increaseAll(1, b, c); // Can pass a literal by value
    // Error: f(a, 2, c); // Cannot pass a literal by ref
    increaseAll(a, b, 3); // Can pass a literal by const ref
    // Passing by ref requires an rvalue
    // Passing by const ref does not require an rvalue
    return 0;
}

void increaseAll(int v, int& r, const int& cr)
{
    cout << "Values:" << endl;
    cout << ++v << endl;
    // Changes the value held at r
    cout << ++r << endl;
    // Error: cout << ++cr << endl;
    int increasedCr = cr + 1;
    cout << increasedCr << endl;
}