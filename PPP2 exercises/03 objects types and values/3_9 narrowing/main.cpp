#include <iostream>
using std::cin, std::cout, std::string, std::endl;

// NOTE: Does not work for large numbers

// List what char this machine will print for any integer value within a given range

int main() {
    int lower_bound = 0;
    int upper_bound = 1;
    cout << "Lowest value: ";
    cin >> lower_bound;
    cout << "Highest value: ";
    cin >> upper_bound;
    for (int i = lower_bound; i <= upper_bound; ++i)
    {
        char c = i;
        cout << i << " becomes " << c << endl;
    }
    return 0;
}
