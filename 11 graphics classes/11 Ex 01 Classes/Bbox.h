//
// Created by Orlando Shamlou on 06/06/2025.
//

#ifndef BBOX_H
#define BBOX_H
#include "PPP/Graph.h"

using namespace Graph_lib;

// Bounding box
// Keep this outside of Shape to prevent clogging the class
struct Bbox {
    Bbox (const Shape& s);
    int min_x;
    int max_x;
    int min_y;
    int max_y;
    int w() const {return max_x - min_x;}
    int h() const {return max_y - min_y;}
};


#endif //BBOX_H
