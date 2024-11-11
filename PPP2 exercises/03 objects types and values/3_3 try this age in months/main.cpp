#include <iostream>
using std::cin, std::cout, std::endl;
#include <string>
using std::string;

// read and print name and age (age in months)
int main() {
    cout << "Please enter your first name and age." << endl;
    // "?" means name is unknown
    string first_name = "?";
    // -1 means age is unknown
    double age = -1;
    cin >> first_name >> age;
    int age_in_months = static_cast<int>(age * 12);
    cout << "Hello " << first_name << " (age: " << age_in_months << " months)." << endl;
    return 0;
}
