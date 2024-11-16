#include "../../PPP_support/PPPheaders.h"

// const member function does not change its object's data
// but can change other data

class Frog {
public:
    void speak(const int& a) const
    {
        for (int i = 0; i < a; ++i) {
            cout << "ribbit" << endl; }
    }
    void do_something(int& a) const {
        ++a;
    }
};

int main() {
    Frog froggie;
    int x = 1;
    froggie.do_something((x));
    froggie.speak(x); // 2 ribbits
}
