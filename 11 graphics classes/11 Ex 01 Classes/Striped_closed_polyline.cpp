//
// Created by Orlando Shamlou on 06/06/2025.
//

// TO COMPLETE!

#include "Striped_closed_polyline.h"

#include "Bbox.h"

void add_fill_lines(Vector_ref<Line>&, const Striped_closed_polyline& s, const Point& a, const Point& b);

void Striped_closed_polyline::draw_specifics(Painter& painter) const {
    Closed_polyline::draw_specifics(painter);
    Bbox b{*this};
    Rectangle r{Point{b.min_x, b.min_y}, b.w(), b.h()};
    // Temp - to demonstrate Bbox
    r.draw_specifics(painter);

    // All lines to draw
    Vector_ref<Line> v;

    // For each y value, a possible set of lines
    for (int i = b.min_y; i < b.max_y; i += 2) {
        // Find all lines from Point{b.min_x, i} to Point{b.max_x, i}
        // 1 pixel of space outside Bbox always to start outside
        add_fill_lines(v, *this, Point{b.min_x-1, i}, Point{b.max_x+1, i});

    }

    // Draw all lines
    for (auto l : v) {
        l->draw_specifics(painter);
    }
}

// Find all lines in s from a to b and push back to v
void add_fill_lines(Vector_ref<Line>& v, const Striped_closed_polyline& s, const Point& a, const Point& b) {
    (void)(s);
    bool in_shape = false;
    int x = a.x;
    while (x < b.x) {
        // Differentiate between intersections and vertices
        // Vertex is only relevant if one Line extends above y and one extends below it

        // How to deal with horizontal Lines? track if shape is above or below y? What if it's both?
        // We detect parallel horizontal lines - both of their points' y values are our y value
        // Ignore them - the state doesn't change. If we are inside before the line, we are inside it after?
        // A horizontal line is a pair of points. We can look at the points before and after that pair - if their y values are both above or below our way (if they are the same), we can ignore the horizontal line.
        // if not, we can't ignore as we have changed from in to out or vice versa
        // We could have a set of points to ignore. When we reach a point that is the start of a horizontal line, we check if we want to ignore its next point

        // Find next intersection
        in_shape = !in_shape;
        // TEMPORARY TO AVOID INFINITE LOOP
        ++x;
    }
    // TEMPORARY TO SHOW FULL LINE
    v.push_back(make_unique<Line>(a, b));
}

bool intersects_horizontal(const Line& l, int y) {
    return (l.point(0).y < y && l.point(1).y > y) || (l.point(0).y > y && l.point(1).y < y);
}

// If either of the line's points are on
bool touches_horizontal(const Line& l, int y) {
    return (y == l.point(0).y || y == l.point(1).y);
}
