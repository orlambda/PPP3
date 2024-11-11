#include "../../PPP_support/PPPheaders.h"

// A declaration is a statement that introduces a name into a scope
    // Specifying a type for what is named
    // Optionally, specifying an initializer (e.g. an initializer value or a function body)

int f(int);

int main() {
    int i = 7;
    std::cout << f(i) << endl;
    return 0;
}

int f(int a) {
    return a + 1;
}