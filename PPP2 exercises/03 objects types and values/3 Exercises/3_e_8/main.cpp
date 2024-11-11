#include <iostream>
using std::cin, std::cout, std::endl;

int main() {
    cout << "Enter an integer: ";
    int val;
    cin >> val;
    bool odd = val % 2;
    if (odd)
    {
        cout << "The value " << val << " is odd." << endl;
    }
    else
    {
        cout << "The value " << val << " is even." << endl;
    }
}