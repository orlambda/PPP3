// //
// // Created by Orlando Shamlou on 04/06/2025.
// //

#include "Striped_rectangle.h"
#include "PPP/Window.h"

void draw_lines(Painter& painter, Point p, int w, int h);

void Striped_rectangle::draw_specifics(Painter& painter) const {
    Rectangle::draw_specifics(painter);
    draw_lines(painter, point(0), width(), height());
}


void draw_lines(Painter& painter, Point p, int w, int h) {
    for (int i = 0; i < h; i += 2) {
        painter.draw_line(Point{p.x, p.y + i}, Point{p.x + w, p.y + i});
    }
}