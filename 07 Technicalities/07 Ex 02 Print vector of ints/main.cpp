#include "../../PPP_support/PPPheaders.h"

void print(const string& label, const vector<int>& v);

int main() {
    const vector<int> v {1, 2, 3};
    const string label = "Numbers: ";
    print(label, v);
}

void print(const string& label, const vector<int>& v)
{
    cout << label;
    for (const int& i : v) {
        cout << i << ", ";
    }
}

