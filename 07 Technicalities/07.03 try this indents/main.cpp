#include "../../PPP_support/PPPheaders.h"

// dangerously ugly code struct X {
void f(int x) {
    struct Y {
        int f() {
            return 1;
        }
        int m; // Unused
    };
    int m;
    m=x; // Unused
    Y m2;
    return f(m2.f()); // m2.f() is 1 so returns f(1)
}

void g(int m)
{
    if (0<m)
        f(m+2);
    else
    { g(m+2.3); }}
X() { }
int m3() {
}
void main() {
    X a;
    a.f(2);} };
