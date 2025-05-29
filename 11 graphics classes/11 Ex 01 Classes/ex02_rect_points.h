//
// Created by Orlando Shamlou on 29/05/2025.
//

#ifndef EX02_RECT_POINTS_H
#define EX02_RECT_POINTS_H
//

// Return points on a Rectangle

Point centre(const Rectangle& r) {
    int x = static_cast<int>(r.point(0).x + r.width() * 0.5);
    int y = static_cast<int>(r.point(0).y + r.height() * 0.5);
    return Point{x, y};
}

Point n(const Rectangle& r) {
    int x = static_cast<int>(r.point(0).x + r.width() * 0.5);
    int y = r.point(0).y;
    return Point{x, y};
}

Point e(const Rectangle& r) {
    int x = (r.point(0).x + r.width());
    int y = static_cast<int>(r.point(0).y + r.height() * 0.5);
    return Point{x, y};
}

Point s(const Rectangle& r) {
    int x = static_cast<int>(r.point(0).x + r.width() * 0.5);
    int y = (r.point(0).y + r.height());
    return Point{x, y};
}

Point w(const Rectangle& r) {
    int x = r.point(0).x;
    int y = static_cast<int>(r.point(0).y + r.height() * 0.5);
    return Point{x, y};
}

Point ne(const Rectangle& r) {
    int x = r.point(0).x + r.width();
    int y = r.point(0).y;
    return Point{x, y};
}

Point nw(const Rectangle& r) {
    return r.point(0);
}

Point se(const Rectangle& r) {
    int x = r.point(0).x + r.width();
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

Point sw(const Rectangle& r) {
    int x = r.point(0).x;
    int y = r.point(0).y + r.height();
    return Point{x, y};
}

#endif //EX02_RECT_POINTS_H
