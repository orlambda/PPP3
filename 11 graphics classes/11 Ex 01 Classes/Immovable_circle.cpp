//
// Created by Orlando Shamlou on 02/06/2025.
//

#include "Immovable_circle.h"

// avoiding 'unused parameter' error
// unused attribute is compiler-specific
// (void)(b) works for all compilers
// can also leave parameter unnamed (int, int)

void Immovable_circle::move(__attribute__((unused)) int a, int b) {
    (void)(b);
    // return;
    throw runtime_error("Cannot move immovable circle");
}