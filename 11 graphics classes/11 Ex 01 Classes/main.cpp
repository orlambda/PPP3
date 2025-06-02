/*
 * Contains solutions to exercises from various chapters from PPP3
 *
 * Ch 11 Exes 01-03: Arrow, rectangle points, circle points, ellipse points
 *
 * Ch 12 Ex 01: Smiley and frowny
 */

#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

#include "Arrow.h"
#include "ex02_rect_points.h"
#include "ex03_circle_ellipse_points.h"
#include "Frowny.h"
#include "Immovable_circle.h"
#include "Smiley.h"

using namespace Graph_lib;
using std::exception;

void ch11(Simple_window& win);

int main()
{
    Application app;
    Simple_window win({20, 20}, 1000, 1000, "Main window");

    // ch11(win); // uncomment to run Ch 11 Exes 01-03

    // ch12ex01
    {
        Frowny c{Point{300,300}, 130};

        win.attach(c);
        win.wait_for_button();

        c.move(400, 400);
        win.wait_for_button(); // uncomment to see this code run

        // How to use arc (segment of a curve = based on an ellipse)
        // point: centre
        // ww/hh: radial
        // s_angle: starting angle in degrees. 0 = E, measured anticlockwise
        // dgr: length of segment 0-360 measured anticlockwise (negative = clockwise)
    }

    // ch12ex04 define a class Immovable_circle, inheriting from Circle
    {
        Immovable_circle i_c{Point{100, 100}, 50};
        win.attach(i_c);
        win.wait_for_button();
        try {
            i_c.move(1, 1); // deleted function
        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
        win.wait_for_button();
    }
}

void ch11(Simple_window& win) {

    // Ch 11 Ex 01 Arrow
    {
        Text text({150, 20}, "Well hello there!");
        win.attach(text);
        Arrow arrow {Point{243,893}, Point{792, 20}};
        win.attach(arrow);
        arrow.set_color(Color::dark_cyan);
        // win.wait_for_button(); // uncomment to see this code run
    }

    // Ch 11 Ex 02 Rectangle points
    {
        // see ex02_rect_points.h
        // Arrow to test code
        Rectangle rect{Point{0,0}, 100, 100};
        win.attach(rect);
        Arrow arrow {centre(rect), sw(rect)};
        win.attach(arrow);
        // win.wait_for_button(); // uncomment to see this code
    }
    // Ch 11 Ex 03 Circle points
    {
        Circle circ{Point{100,100}, 100};
        win.attach(circ);
        Arrow arrow {centre(circ),sw(circ)};
        win.attach(arrow);
        // win.wait_for_button(); // uncomment to see this code
    }
    // Ch 11 Ex 03 Ellipse points
    {
        Ellipse el{Point{200,200}, 200, 100};
        win.attach(el);
        Arrow arrow {centre(el),se(el)};
        win.attach(arrow);
        win.wait_for_button();
    }
}