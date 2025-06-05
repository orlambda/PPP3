//
// Created by Orlando Shamlou on 04/06/2025.
//

#ifndef STRIPED_RECTANGLE_H
#define STRIPED_RECTANGLE_H

#include "PPP/Graph.h"
using namespace Graph_lib;

struct Striped_rectangle : Rectangle {
public:
    using Rectangle::Rectangle;
    void draw_specifics(Painter& painter) const override;
};



#endif //STRIPED_RECTANGLE_H
