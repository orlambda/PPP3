#include "B1.h"

int main(int /*argc*/, char* /*argv*/[])
{

    // cout << "b1:" << endl;
    // B1 b1;
    // b1.vf();
    // b1.f();

    // Make a D1 object and call vf() and f() for it.
    cout << "d1:" << endl;
    D1 d1;
    d1.vf();
    d1.f();

    // Define a reference to B1 (a B1&) and initialize that to the D1 object you just defined. Call vf()
    // and f()for that reference.
    cout << "b1ref:" << endl;
    B1& b1ref{d1};
    b1ref.vf();
    b1ref.f();

    // Now define a function called f() for D1 and repeat 1–3. Explain the results.

    // Make an object of class D2 and invoke f(), vf(), and pvf() for it.
    cout << "d2:" << endl;
    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    // Call f() with a D21 and a D22.
    D21 d21;
    D22 d22;
    cout << "d21: " << endl;
    f(d21);
    cout << "d22: " << endl;
    f(d22);

}
