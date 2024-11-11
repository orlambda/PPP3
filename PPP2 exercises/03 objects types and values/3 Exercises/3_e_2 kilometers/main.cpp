#include <iostream>
using std::cin, std::cout, std::endl;

// Convert miles to kilometres
int main() {
    // 1 mile = 1.60934 kilometres
    // Prompt for miles
    cout << "Enter miles: ";
    double miles = 0;
    cin >> miles;
    double kilometres = miles * 1.60934;
    cout << kilometres << " kilometres." << endl;
    return 0;
}
