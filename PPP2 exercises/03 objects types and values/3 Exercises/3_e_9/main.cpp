#include <iostream>
using std::cin, std::cout, std::endl, std::string;

int main()
{
    cout << "Write an integer from zero to four: ";
    string val;
    cin >> val;
    if (val == "zero" || val == "nought")
    {
        cout << 0 << endl;
    }
    else if (val == "one")
    {
        cout << 1 << endl;
    }
    else if (val == "two")
    {
        cout << 2 << endl;
    }
    else if (val == "three")
    {
        cout << 3 << endl;
    }
    else
    {
        cout << "not a number I know" << endl;
    }
}