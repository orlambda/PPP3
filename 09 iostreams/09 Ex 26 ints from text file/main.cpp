/*
 *Created by Orlando Shamlou on 2025/06/03
 *
 *PPP3 Ch 09 Ex 26
 *Write a program that produces the sum of all the whitespace-separated integers in a text file.
 *For example, "bears: 17 elephants 9 end" should output 26.
 *
 *This code ignores numbers with a decimal point
 *This could be improved to check for only zeroes after a decimal point and to accept scientific notation
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout, std::endl, std::ifstream, std::ofstream, std::runtime_error, std::string, std::istringstream;

int add_all_ints(std::ifstream& is);
bool contains(const string& s, const char& p_c);

int main() {

    // Could take filename as input
    const string iname = "input.txt";

    // // Open file to read
    ifstream ifile{iname};
    if (!ifile) {
        throw runtime_error("Error: cannot open " + iname);
    }

    // Aiming for 101
    int sum = add_all_ints(ifile);
    cout << "All integers in " << iname << " add up to " << sum << "." << endl;
}

int add_all_ints(std::ifstream& p_is) {
    int sum = 0;
    string s;
    while (p_is >> s) {
        cout << s << endl;
        // We don't want to include floats
        if (contains(s, '.')) {
            continue;
        }
        istringstream is{s};
        int i = 0;
        if (is >> i) {
            // Reject integers connected to letters
            if (s == std::to_string(i)) {
                sum += i;
            }
        }
    }
    return sum;
}

bool contains(const string& s, const char& p_c) {
    for (auto c: s) {
        if (c == p_c) {
            return true;
        }
    }
    return false;
}