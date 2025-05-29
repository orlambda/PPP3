//
// Created by Orlando Shamlou on 28/05/2025.
//

#ifndef ARROW_H
#define ARROW_H
#include "PPP/Graph.h"

using namespace Graph_lib;

struct Arrow : Lines {
public:
    Arrow(Point a, Point b);

};

double angle_between_points(Point a, Point b);

Point point_from_centre(Point origin, double angle_in_radians, double radius);



#endif //ARROW_H
