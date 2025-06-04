//
// Created by Orlando Shamlou on 04/06/2025.
//

#include "Improved_ellipse.h"
#include <cmath>

double Improved_ellipse::focal_length() const {
    return sqrt(abs(pow(major(), 2)-pow(minor(), 2)));
}

double Improved_ellipse::semi_latus_rectum() const {
    return pow(minor(), 2) / major();
}

Point Improved_ellipse::nw() const {
    return Point {
        focus2().x, static_cast<int>(focus2().y - semi_latus_rectum())
    };
}
Point Improved_ellipse::ne() const {
    return Point{
        focus1().x, static_cast<int>(focus1().y - semi_latus_rectum())
    };
}
Point Improved_ellipse::sw() const {
    return Point{
        focus2().x, static_cast<int>(focus2().y + semi_latus_rectum())
    };
}
Point Improved_ellipse::se() const {
    return Point{
        focus1().x, static_cast<int>(focus1().y + semi_latus_rectum())
    };
}