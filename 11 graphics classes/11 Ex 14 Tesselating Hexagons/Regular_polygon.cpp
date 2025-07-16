//
// Created by Orlando Shamlou on 04/06/2025.
//

#include "Regular_polygon.h"

#include <numbers>

constexpr double pi = std::numbers::pi;

// This gives angle measuring anti-clockwise
// Use commented out line instead to measure clockwise
Point point_from_centre (Point origin, double angle_in_radians, double radius) {
    int x = static_cast<int>(cos(angle_in_radians) * radius);
    // int y = static_cast<int>((sin(angle_in_radians) * radius));
    int y = static_cast<int>(-(sin(angle_in_radians) * radius));
    return Point{x + origin.x, y + origin.y};
}


Regular_polygon::Regular_polygon(Point centre, int p_sides, double p_circumradius, double p_rotation) {
    if (p_circumradius <= 0) {
        throw std::runtime_error("Regular polygon circumradius must be above 0");
    }
    if (p_sides < 3) {
        throw std::runtime_error("Regular polygon must have at least 3 sides");
    }
    c = centre;
    radius = p_circumradius;
    n = p_sides;
    rotation_ = p_rotation;
    double angle = rotation_;
    // TODO: move to draw_specifics?
    // check if call draw in constructor?
    for (int i = 0; i < n; ++i) {
        add(point_from_centre(centre, angle, radius));
        // TODO: decide if this is to be treated as clockwise or anticlockwise
        // currently anticlockwise
        // check Ellipse
        angle += (2.0*pi)/n;
    }
}

double Regular_polygon::inradius() {
    return circumradius() * cos(pi/n);
}

double Regular_polygon::circumradius() {
    return radius;
}

Point Regular_polygon::centre() {
    return c;
}

double Regular_polygon::rotation() {
    return rotation_;
}
