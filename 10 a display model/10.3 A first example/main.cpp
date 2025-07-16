#include <complex>

#include "PPP/Simple_window.h"
#include "PPP/Graph.h"

using namespace Graph_lib;

double dsin(double d);

int main(int /*argc*/, char* /*argv*/[])
{
    Application app;

    Point tl {900, 500};

    Simple_window win {tl,600,400,"Canvas"};

    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::red);
    win.attach(poly);
    win.wait_for_button();

    win.detach(poly);
    Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
    win.attach((xa));
    win.set_label("X axis");
    win.wait_for_button();
    Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::green);
    win.attach(ya);
    win.wait_for_button();

    Function sine {dsin,0,100,Point{20,150},1000,50,50};
    sine .set_color(Color::blue);
    win.attach(sine);
    win.set_label("Sine");
    win.wait_for_button();
    win.attach(poly);
    win.set_label("Sine and triangle");
    win.wait_for_button();

    Rectangle r {Point{200,200}, 100, 50};
    r.set_color(Color::dark_cyan);
    win.attach(r);
    win.set_label("Sine, triangle, and rectangle");
    win.wait_for_button();

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    win.attach(poly_rect);
    win.set_label("Polyline");
    win.attach(poly_rect);
    win.wait_for_button();

    poly_rect.add(Point{50,75});
    win.set_label("Polyline 2");
    win.wait_for_button();

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dashdot,4));
    poly_rect.set_style(Line_style(Line_style::dash,2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("Fill");
    win.wait_for_button();

    Text t {Point{150,150}, "Hello, graphical world!"};
    win.attach(t);
    win.set_label("Text");
    win.wait_for_button();

    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.set_label("Bold text");
    win.wait_for_button();

    Image copter {Point{100,50},"penul.jpg"};
    win.attach(copter);
    win.set_label("Dragon");
    win.wait_for_button();
}

double dsin(double d) { return sin(d); }