//
// Created by Orlando Shamlou on 04/06/2025.
//

#ifndef REGULAR_POLYGON_H
#define REGULAR_POLYGON_H
#include "PPP/Graph.h"

using namespace Graph_lib;;


struct Regular_polygon : Polygon {
    // TODO: where to initialise private variables?
public:
    Regular_polygon(Point p_centre, int p_sides, double p_circumradius, double p_rotation=0);
    using Polygon::draw_specifics;
    double inradius();
    double circumradius();
    double rotation();
    Point centre();
private:
    // circumradius
    double radius;
    double rotation_;
    double n;
    Point c;
};



#endif //REGULAR_POLYGON_H
