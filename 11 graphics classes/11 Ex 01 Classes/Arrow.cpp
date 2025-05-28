//
// Created by Orlando Shamlou on 28/05/2025.
//

#include <cmath>
#include <numbers>

#include "Arrow.h"

constexpr double pi = std::numbers::pi;

Arrow::Arrow(Point a, Point b) {
    add(a, b);
    // Calculation for arrowhead
    // Find direction vector
    // Measures angle clockwise from East
    double direction_radians = angle_between_points(a, b);
    cout << direction_radians << endl;
    double direction_arrowhead_a = direction_radians;
    double direction_arrowhead_b = direction_radians;
    // Hardcoded - could be a percentage of line length, or input as length or percentage
    double arrowhead_length = 20;
    double arrowhead_angle = pi*2*0.42;
    Point arrowhead_a = point_from_centre(b, direction_arrowhead_a - arrowhead_angle, arrowhead_length);
    Point arrowhead_b = point_from_centre(b, direction_arrowhead_b + arrowhead_angle, arrowhead_length);


    // cout << direction_radians << endl;
    // These could be stored separately to allow them to be styled separately
    // Or arrowhead styling could just target them by index
    add(arrowhead_a, b);
    add(arrowhead_b, b);
}

// Radians, measured clockwise from East
double angle_between_points(Point a, Point b) {
    Point direction{b.x - a.x, b.y- a.y};
    return atan2(direction.y, direction.x);
}


// Measured clockwise
Point point_from_centre (Point origin, double angle_in_radians, double radius) {
    int x = static_cast<int>(cos(angle_in_radians) * radius);
    int y = static_cast<int>((sin(angle_in_radians) * radius)); // fixed to measure clockwise
    // int y = static_cast<int>(-(sin(angle_in_radians) * radius));
    return Point{x + origin.x, y + origin.y};
}