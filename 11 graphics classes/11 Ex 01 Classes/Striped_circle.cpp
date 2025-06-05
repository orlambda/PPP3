//
// Created by Orlando Shamlou on 05/06/2025.
//

#include "PPP/Window.h"

#include "Striped_circle.h"


void draw_lines(Painter& painter, Point p, int r);

void Striped_circle::draw_specifics(Painter& painter) const {
    Circle::draw_specifics(painter);
    draw_lines(painter, center(), radius());
}

void draw_lines(Painter& painter, Point p, int r) {
    for (int i = 0; i < r*2; i += 2) {
        int y = p.y + i - r;
        // x, calculate distance horizontally from centre = adj
        // Right angle triangle, hypotenuse from centre to edge of circle
        // HYP = r
        // adj = x
        // opp = r - i
        int x1 = p.x - static_cast<int>(sqrt(pow(r, 2) - pow(r - i, 2)));
        int x2 = p.x + static_cast<int>(sqrt(pow(r, 2) - pow(r - i, 2)));
        painter.draw_line(Point{x1, y}, Point{x2, y});
    }
}