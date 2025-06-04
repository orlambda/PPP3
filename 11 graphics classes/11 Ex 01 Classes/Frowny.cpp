//
// Created by Orlando Shamlou on 02/06/2025.
//

#include "Frowny.h"



void Frowny::draw_specifics(Painter& painter) const {
    Circle::draw_specifics(painter);
    left_eye.draw_specifics(painter);
    right_eye.draw_specifics(painter);
    mouth.draw_specifics(painter);
}

void Frowny::move(int dx, int dy) {
    Shape::move(dx,dy);
    left_eye.move(dx, dy);
    right_eye.move(dx, dy);
    mouth.move(dx, dy);
    redraw();
}