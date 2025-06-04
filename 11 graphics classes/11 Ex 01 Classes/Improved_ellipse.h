//
// Created by Orlando Shamlou on 04/06/2025.
//



#ifndef IMPROVED_ELLIPSE_H
#define IMPROVED_ELLIPSE_H
#include "PPP/Graph.h"
using namespace Graph_lib;


struct Improved_ellipse : Ellipse {
public:
    using Ellipse::Ellipse;
    double focal_length() const;
    double semi_latus_rectum() const;
    Point nw() const;
    Point ne() const;
    Point sw() const;
    Point se() const;
    // using Shape::move; // QUESTION: is this necessary?
private:
};



#endif //IMPROVED_ELLIPSE_H
