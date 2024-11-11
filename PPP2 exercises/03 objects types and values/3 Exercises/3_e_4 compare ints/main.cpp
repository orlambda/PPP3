#include <iostream>
using std::cin, std::cout, std::endl, std::string;

int main() {
     cout << "Enter two integers to compare: ";
     int val1 = 0;
     int val2 = 0;
     cin >> val1 >> val2;
     // -1 means uninitiated, 0 means equal, 1 means val1 is higher, 2 means val2 is higher
     int highest_value = -1;
     if (val1 > val2)
     {
         cout << val1 << " is higher than " << val2 << endl;
         highest_value = 1;
     }
     else if (val1 < val2)
     {
         cout << val1 << " is less than " << val2 << endl;
         highest_value = 2;
     }
     else
     {
         cout << val1 << " is the same as " << val2 << endl;
         highest_value = 0;
     }
     cout << "Sum: " << val1 + val2 << endl;
     cout << "Difference: " << abs(val1 - val2) << endl;
     cout << "Product: " << val1 * val2 << endl;
     cout << "Ratio: " << double(val1)/val2 << ":1"<< endl;
}
