//
// Created by Orlando Shamlou on 31/05/2025.
//

#ifndef SMILEY_H
#define SMILEY_H

#include "PPP/Graph.h"

using namespace Graph_lib;

// TODO:
// Search for every definition give of move() - search for 'move('
// Should I be using points? Can mvoe automatically redraw the extra features? line etc

// See Circle class p342
struct Smiley : Circle {
public:
    using Circle::Circle;
    void draw_specifics(Painter& painter) const override;
    void move(int dx, int dy) override;
private:
    int r = radius();
    // Facial features - values relative to face radius
    static constexpr double eye_radius = 0.2;
    static constexpr double horizontal_eye_offset = 0.3;
    static constexpr double vertical_eye_offset = 0.3;
    static constexpr double mouth_half_width = 0.4;
    static constexpr double mouth_height = 0.1;
    static constexpr double mouth_vertical_offset = 0.3;
    Circle left_eye {center() + Point{static_cast<int>(-r * horizontal_eye_offset), static_cast<int>(-r*vertical_eye_offset)}, static_cast<int>(r * eye_radius)};
    Circle right_eye {center() + Point{static_cast<int>(r * horizontal_eye_offset), static_cast<int>(-r*vertical_eye_offset)}, static_cast<int>(r * eye_radius)};
    Arc mouth {center() + Point{0,static_cast<int>(r * mouth_vertical_offset)}, static_cast<int>(r * mouth_half_width), static_cast<int>(r * mouth_height), -10, -160};
    // Arc mouth {center(), 50, 50, 0, 180};
};

#endif //SMILEY_H
