//
// Created by Orlando Shamlou on 05/06/2025.
//

#ifndef STRIPED_CIRCLE_H
#define STRIPED_CIRCLE_H
#include "PPP/Graph.h"
using namespace Graph_lib;


struct Striped_circle : Circle {
public:
    using Circle::Circle;
    void draw_specifics(Painter& painter) const override;
private:
};



#endif //STRIPED_CIRCLE_H
