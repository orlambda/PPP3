// Created by Orlando Shamlou on 2025/07/18

// Following §13 Drill: Graphing Functions

#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

double one(double x) {
    (void)x;
    return 1;
}

double slope(double x)
{
    return x * 0.5;
}

double square(double x)
{
    return x * x;
}

double sloping_cos(double x)
{
    return cos(x) + slope(x);
}

int main(int /*argc*/, char* /*argv*/[])
{
    constexpr int x_max = 1000;
    constexpr int y_max = 1000;
    constexpr int axis_length = 400;
    constexpr int scale = 20;
    constexpr int notches = axis_length / scale;
    constexpr Point origin{x_max / 2,y_max / 2};

    Application app;
    Simple_window window({20, 20}, x_max, y_max, "Function graphs");


    Axis x{Axis::Orientation::x, Point{origin.x - axis_length / 2, origin.y}, axis_length, notches, "1 == " + to_string(scale) + " pixels"};
    Axis y{Axis::Orientation::y, Point{origin.x, origin.y + axis_length / 2}, axis_length, notches, "1 == " + to_string(scale) + " pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    window.attach(x);
    window.attach(y);

    // Graph function
    Function f1{one, -10, 11, origin, 400, scale, scale};
    window.attach(f1);

    Function f2{slope, -10, 11, origin, 400, scale, scale};
    Text l2{Point{origin.x - 200, origin.y + 60}, "0.5x"};
    window.attach(f2);
    window.attach(l2);

    Function f3{square, -10, 11, origin, 400, scale, scale};
    window.attach(f3);

    Function f4{[](double x){return cos(x);}, -10, 11, origin, 400, scale, scale};
    f4.set_color(Color::blue);
    window.attach(f4);

    Function f5{sloping_cos, -10, 11, origin, 400, scale, scale};
    f5.set_color(Color::green);
    window.attach(f5);

    app.gui_main();


}
