//
// Created by Orlando Shamlou on 06/06/2025.
//

#include "Bbox.h"

Bbox::Bbox(const Shape& s) {
    if (s.number_of_points() < 1) {
        throw std::runtime_error("Shape has no points");
    }

    // Cannot assume a minimum or maximum possible value
    min_x = s.point(0).x;
    max_x = s.point(0).y;
    min_y = s.point(0).y;
    max_y = s.point(0).y;

    // Loop through points
    for (int i = 0; i < s.number_of_points(); ++i) {
        int x = s.point(i).x;
        int y = s.point(i).y;
        if (x < min_x) {min_x = x;}
        if (x > max_x) {max_x = x;}
        if (y < min_y) {min_y = y;}
        if (y > max_y) {max_y = y;}
    }
}