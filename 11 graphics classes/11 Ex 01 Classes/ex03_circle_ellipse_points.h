//
// Created by Orlando Shamlou on 29/05/2025.
//

#ifndef EX03_CIRCLE_ELLIPSE_POINTS_H
#define EX03_CIRCLE_ELLIPSE_POINTS_H

// Using point_from_centre() which would be better placed in another file
#include <numbers>

#include "Arrow.h"

constexpr double pi = std::numbers::pi;

// Return points on a Circle

Point centre(const Circle& r) {
    return r.center();
}

Point n(const Circle& r) {
    return Point{r.center().x, r.center().y - r.radius()};
}

Point e(const Circle& r) {
    return Point{r.center().x + r.radius(), r.center().y};
}

Point s(const Circle& r) {
    return Point{r.center().x, r.center().y + r.radius()};
}

Point w(const Circle& r) {
    return Point{r.center().x - r.radius(), r.center().y};
}

Point ne(const Circle& r) {
    return point_from_centre(r.center(), pi * 1.75, r.radius());
}

Point nw(const Circle& r) {
    return point_from_centre(r.center(), pi * 1.25, r.radius());
}

Point se(const Circle& r) {
    return point_from_centre(r.center(), pi * 0.25, r.radius());
}

Point sw(const Circle& r) {
    return point_from_centre(r.center(), pi * 0.75, r.radius());
}

// Return points on an Ellipse
// Major is width, minor is height, regardless of which is greater (this is how Ellipse class is defined)

Point centre(const Ellipse& r) {
    return r.center();
}

Point n(const Ellipse& r) {
    return Point{r.center().x, r.center().y - r.minor()};
}

Point e(const Ellipse& r) {
    return Point{r.center().x + r.major(), r.center().y};
}

Point s(const Ellipse& r) {
    return Point{r.center().x, r.center().y + r.minor()};
}

Point w(const Ellipse& r) {
    return Point{r.center().x - r.major(), r.center().y};
}

Point ne(const Ellipse& r) {
    return Point{r.center().x + r.major(), r.center().y - r.minor()};
}

Point nw(const Ellipse& r) {
    return Point{r.center().x - r.major(), r.center().y - r.minor()};
}

Point se(const Ellipse& r) {
    return Point{r.center().x + r.major(), r.center().y + r.minor()};
}

Point sw(const Ellipse& r) {
    return Point{r.center().x - r.major(), r.center().y + r.minor()};
}


#endif //EX03_CIRCLE_ELLIPSE_POINTS_H
