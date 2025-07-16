//
// Created by Orlando Shamlou on 06/06/2025.
//

#ifndef STRIPED_POLYLINE_H
#define STRIPED_POLYLINE_H
#include "PPP/Graph.h"

using namespace Graph_lib;


struct Striped_closed_polyline : Closed_polyline {
    using Closed_polyline::Closed_polyline;
    void draw_specifics(Painter& painter) const override;
};



#endif //STRIPED_POLYLINE_H
