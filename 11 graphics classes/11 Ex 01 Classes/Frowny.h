//
// Created by Orlando Shamlou on 02/06/2025.
//

#ifndef FROWNY_H
#define FROWNY_H

#include "PPP/Graph.h"

using namespace Graph_lib;

// Note: This should inherit from Smiley - or Frowny and Smiley should inherit from a Face class
// Both inherit from Circle as specified in the given exercise
// Or have in a single class and configure with parameters

// See Circle class p342
struct Frowny : Circle {
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
    static constexpr double mouth_vertical_offset = 0.5;
    Circle left_eye {center() + Point{static_cast<int>(-r * horizontal_eye_offset), static_cast<int>(-r*vertical_eye_offset)}, static_cast<int>(r * eye_radius)};
    Circle right_eye {center() + Point{static_cast<int>(r * horizontal_eye_offset), static_cast<int>(-r*vertical_eye_offset)}, static_cast<int>(r * eye_radius)};
    Arc mouth {center() + Point{0,static_cast<int>(r * mouth_vertical_offset)}, static_cast<int>(r * mouth_half_width), static_cast<int>(r * mouth_height), 10, 160};
};

#endif //FROWNY_H
