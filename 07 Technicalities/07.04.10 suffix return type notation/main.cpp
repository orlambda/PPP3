#include "../../PPP_support/PPPheaders.h"

auto add1(int x) -> int;
int add2(int x);

// PPP3 says suffix return type notation is sometimes essential. I don't understand why.

auto create_single_element_vector(string s) -> const vector<string>;
const vector<string> create_single_element_vector2(string s);

int main() {
    // Print 1 2
    cout << add1(0) << " " << add2(0) << endl;
    cout << create_single_element_vector("Hello, ")[0] << create_single_element_vector2("World!")[0] << endl;
}


auto add1(int x) -> int
{
    return x + 1;
}
int add2(int x)
{
    return x + 2;
}

auto create_single_element_vector(string s) -> const vector<string>
{
    vector<string> v;
    v.push_back(s);
    return v;
}

const vector<string> create_single_element_vector2(string s)
{
    vector<string> v;
    v.push_back(s);
    return v;
}