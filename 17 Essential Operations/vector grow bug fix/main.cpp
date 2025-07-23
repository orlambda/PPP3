// Fixes a bug in grow() from PPP3 §17.7

// now increment n in for loop
// initialise i in for loop
// copy vector to double in correct scope

#include <iostream>

using std::cin, std::cout, std::endl, std::vector;

void grow(vector<int>& v)
{
    int n = 0;
    for (double d; cin >> d; ++n)
    {
        if (n == v.size())
        {
            vector<int> v2(v.size()+1);
            for (int i=0; i < v.size(); ++i)
            {
                v2[i] = v[i];
            }
            v = v2;
        }
        v[n] = d;
    }

}


int main()
{
    vector<int> v;
    grow(v);
    for (auto e: v)
    {
        cout << e << endl;
    }
}