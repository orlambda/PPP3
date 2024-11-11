#include <iostream>
using std::cout, std::endl;

int main() {
    // PPP asserts that for two positive ints a and b we have a/b * b + a%b == a
    int true_count = 0;
    int false_count = 0;

    for (int a = 1; a <= 100; ++a)
    {
        for (int b = 1; b <= 100; ++b)
        {
            bool result = (a/b * b + a%b == a);
            if (result)
            {
                // cout << a << " and " << b << endl;
                ++true_count;
            }
            else
            {
                cout << "Error with " << a << " and " << b << endl;
                ++false_count;
            }
        }
    }
    cout << "True count: " << true_count << endl
    << "False count: " << false_count << endl;
    return false_count;
}
