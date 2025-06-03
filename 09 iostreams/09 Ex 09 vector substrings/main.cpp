/*Created by Orlando Shamlou on 2025/06/03
 *
 *PPP Ch 09 Ex 09
 *Take a string and return a vector of substrings split by whitespace
 *
 *PPP Ch 09 Ex 10
 *Take a string and return a vector of substrings split by whitespace and given delimiters
 *
 *A more elegant solution would be to use Regex to check for the delimiters
 *I chose not to use this as the book hasn't covered this yet
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using std::vector, std::string, std::cout, std::endl;

bool contains(const string& s, const char& p_c);
vector<string> split(const string& s);
vector<string> split(const string& s, const string& delimiters);

int main() {
    // Split by whitespace
    {
        string test_string = "This\fshould\nbe\tsplit up into\rexactly 9.0\vsub-strings!";
        vector<string> v = split(test_string);
        for (const auto& substring : v) {
            cout << substring << endl;
        }
        cout << "Substring count: " << v.size() << endl;
    }
    cout << endl;
    // Split by whitespace and given delimiters
    {
        string test_string = "This\fshould\nbe\tsplit up into\rexactly 14.0\vsub-strings!";
        vector<string> v = split(test_string, "pic");
        for (const auto& substring : v) {
            cout << substring << endl;
        }
        cout << "Substring count: " << v.size() << endl;
    }
}

bool contains(const string& s, const char& p_c) {
    for (auto c: s) {
        if (c == p_c) {
            return true;
        }
    }
    return false;
}

vector<string> split(const string& s) {
    vector<string> v;
    std::istringstream is{s};
    string temp;
    while (is >> temp) {
        v.push_back(temp);
    }
    return v;
}

vector<string> split(const string& s, const string& delimiters) {
    vector<string> v;
    std::istringstream is{s};
    string temp;
    // Split by whitespace
    while (is >> temp) {
        string final_substring;
        // Split by delimiters
        for (auto c : temp) {
            if (!contains(delimiters, c)) {
                final_substring += c;
            }
            else if (!final_substring.empty()) {
                v.push_back(final_substring);
                final_substring = "";
            }
        }
        if (!final_substring.empty()) {
            v.push_back(final_substring);
        }
    }
    return v;
}