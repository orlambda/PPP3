#include "../../PPP_support/PPPheaders.h"

void do_stuff();

int main() {
    for (int i = 0; i < 2; ++i) {
        do_stuff();
    }
}

void do_stuff() {
    {
        int i = 0;
        while (i < 5)

        {
            // This gets constructed 5 times
            vector<int> v;
            v.push_back(1);
            // Size is always 1
            cout << "Vector1 size: " << v.size() << endl;

            // This gets constructed once
            static vector<int> v2;
            v2.push_back(i);
            cout << "Vector2 (static) size: " << v2.size() << endl;
            cout << "Vector2 (static) last int: " << v2[v2.size()-1] << endl;

            int x;
            // Uninitialized on the first iteration
            cout << "x: " << x << endl;
            x = i;

            static int y;
            // Uninitialized on the first iteration
            cout << "y (static): " << y << endl;
            y = i;

            ++i;
        }
    }
}
