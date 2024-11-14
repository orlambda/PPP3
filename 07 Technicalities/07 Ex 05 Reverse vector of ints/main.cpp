#include <iostream>
#include <string>
#include <vector>
using std::cout, std::endl;

std::vector<int> reverse(const std::vector<int>& v);
void reverse_in_place(std::vector<int>& v);
void print(const std::string& label, const std::vector<int>& v);

int main() {
    std::vector<int> v {10, 20, 30, 40};
    const std::string label = "Reversed std::vector: ";
    print(label, reverse(v));
    cout << endl;
    reverse_in_place(v);
    print(label, v);
    cout << endl;
}

// Return a new std::vector
std::vector<int> reverse(const std::vector<int>& v)
{
    std::vector<int> output;
    output.reserve(v.size());
    for (int i = 0; i < v.size(); ++i) {
        output.push_back(v[v.size() - i - 1]);
    }
    return output;
}

void reverse_in_place(std::vector<int>& v)
{
    // from i to the middle, rounding down
    for (int i = 0; i < (v.size() / 2); ++i) {
        std::swap(v[i], v[v.size() - i - 1]);
    }

}

void print(const std::string& label, const std::vector<int>& v)
{
    cout << label;
    for (const int& i : v) {
        cout << i << ", ";
    }
}