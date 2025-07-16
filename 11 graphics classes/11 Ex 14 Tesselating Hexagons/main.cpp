// Created by Orlando Shamlou on 2025/06/04
// PPP3 Ch 11 Ex 14
// Draw a window of tesselating regular hexagons
// Improvements:
    // Make sure lines don't overlap
        // Could draw not hexagons but polylines of 3 segments, but then couldn't fill hexagons
        // Possibly rather than construct each hexagon from its centre, calculate the points first,
        // so each hexagon's points are identical, and build from that.
        // Either calculate all points first - not ideal - or row by row, leaving a buffer
        // Or - vectors of all x and y values to be then combined into points
    // Give make_row fewer parameters



#include <cmath>
#include <numbers>

#include "Regular_polygon.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

Point point_from_centre (Point origin, double angle_in_radians, double radius);


void make_row(Vector_ref<Regular_polygon>& v, int circumradius, Point origin, int length, int spacing, int y, int x_offset);
void make_hex_grid(Vector_ref<Regular_polygon>& v, int x, int y, int radius);



int main(int /*argc*/, char* /*argv*/[]) {
    Application app;
    int x_max = 1000;
    int y_max = 1000;
    Simple_window win({20, 20}, x_max, y_max, "Main window");

    Vector_ref<Regular_polygon> v;

    make_hex_grid(v, x_max, y_max, 20);
    for (auto p : v) {
        win.attach(*p);
    }
    win.wait_for_button();
}


void make_hex_grid(Vector_ref<Regular_polygon> &v, int x, int y, int radius) {
    // To get measurements
    Regular_polygon dummy_hex {Point{0,0},6, double(radius),0};
    int x_offset = radius * 0.75;
    for (int i = 0-radius; i < y+radius; i += dummy_hex.inradius()) {
        cout << dummy_hex.circumradius() << " " << dummy_hex.inradius() << " ";
        x_offset = -x_offset;
        make_row(
        v, static_cast<int>(dummy_hex.circumradius()),
        Point{static_cast<int>(0-dummy_hex.circumradius()),0},
        static_cast<int>(x+dummy_hex.circumradius()*2), static_cast<int>(dummy_hex.circumradius()*3), i, x_offset);
    }
}



void make_row(Vector_ref<Regular_polygon>& v, int circumradius, Point origin, int length, int spacing, int y, int x_offset) {
    for (int i = 0; i < length; i += spacing) {
        v.push_back(make_unique<Regular_polygon>(Point{origin.x + i + x_offset, y}, 6, circumradius));
    }
}