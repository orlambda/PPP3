/*
 *Created by Orlando Shamlou on 2025/06/03
 *PPP3 §9 Ex 01
 *Read a text file, convert it to all lowercase, and write to a new file
 */

// #include "../../PPP_support/PPPheaders.h"
#include <iostream>
#include <fstream>
using std::ifstream, std::ofstream, std::string, std::runtime_error, std::getline, std::cout, std::endl;

int main() {

    // Could take filenames as input
    const string iname = "input.txt";
    const string oname = "output.txt";

    // // Open files to read and write
    ifstream ifile{iname};
    if (!ifile) {
        throw runtime_error("Error: cannot open " + iname);
    }
    ofstream ofile{oname};
    if (!ofile) {
        throw runtime_error("Error: cannot open " + oname);
    }

    // Read ifile line by line
    string s;
    while (getline(ifile, s)) {
        // Convert each char to lowercase and write to ofile
        for (auto& c : s) {
            // QUESTION: how to convert 'É' to lower case?
            ofile << static_cast<char>(tolower(c));
            // ofile << static_cast<unsigned char>(tolower(static_cast<unsigned char>(c)));
            // ofile << static_cast<char>(towlower(c));
        }
        // QUESTION: is this the right way to add newlines? this results in one extra newline at end of file
        ofile << std::endl;
    }
}
