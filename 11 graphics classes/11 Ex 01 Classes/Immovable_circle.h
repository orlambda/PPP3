//
// Created by Orlando Shamlou on 02/06/2025.
//

#ifndef IMMOVABLE_CIRCLE_H
#define IMMOVABLE_CIRCLE_H
#include "PPP/Graph.h"

using namespace Graph_lib;

struct Immovable_circle : Circle {
public:
    // void move(int a, int b)override=delete; // error: cannot override a non-deleted function
    void move(int a, int b) override;
private:
    using Circle::Circle;
};



#endif //IMMOVABLE_CIRCLE_H
