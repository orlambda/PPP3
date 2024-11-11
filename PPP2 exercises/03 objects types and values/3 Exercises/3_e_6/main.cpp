#include <iostream>
using std::cout, std::cin, std::endl;

int main() {
    cout << "Enter three integers." << endl;
    int val1;
    int val2;
    int val3;
    cin >> val1 >> val2 >> val3;
    // If val1 is the lowest number
    if (val1 <= val2 && val1 <= val3)
    {
        cout << val1 << " ";
        if (val2 <= val3)
        {
            cout << val2 << " " << val3 << endl;
        }
        else
        {
            cout << val3 << " " << val2 << endl;
        }
    }
    // If val2 is the lowest number
    else if (val2 <= val3)
    {
        cout << val2 << " ";
        if (val1 <= val3)
        {
            cout << val1 << " " << val3 << endl;
        }
        else
        {
            cout << val3 << " " << val1 << endl;
        }
    }
    // If val3 is the lowest number
    else
    {
        cout << val3 << " ";
        if (val2 <= val1)
        {
            cout << val2 << " " << val1 << endl;
        }
        else
        {
            cout << val1 << " " << val2 << endl;
        }
    }
}
