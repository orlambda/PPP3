#include "../../PPP_support/PPPheaders.h"

// This function from exercise 2
void print(const string& label, const vector<int>& v);
void fibonacci(int a, int b, vector<int>& v, int n);
int nextFibonnaciNumber(int a, int b);
void initialize_sequence(int a, int b, vector<int>& v, int n);

int main() {
    vector<int> sequence;
    fibonacci(0, 1, sequence, 1000000000);
    const string label = "Sequence: ";
    print(label, sequence);
}

void print(const string& label, const vector<int>& v)
{
    cout << label;
    for (const int& i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void fibonacci(int a, int b, vector<int>& v, int n)
{
    if (n < 0) {
        return;
    }
    if (v.empty()) {
        // Take care of cases where n < 2
        initialize_sequence(a, b, v, n);
    }
    while (v.size() < n) {
        int next = nextFibonnaciNumber(v[v.size()-1], v[v.size()-2]);
        // Check for overflow
        if (next < 0) {
            cout << "Approximate max int: " << v.back();
            error("Integer overflow");
        }
        v.push_back(next);
    }
}

// Very unnecessary function
// But maybe good to separate for future use with other sequences
int nextFibonnaciNumber(int a, int b) {
    return a + b; }

void initialize_sequence(int a, int b, vector<int>& v, int n)
{
    if (n < 1) {
        return; }
    v.push_back(a);
    if (n > 1) {
        v.push_back(b); }
}