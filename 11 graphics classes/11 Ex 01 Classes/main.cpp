/*
 * Contains solutions to exercises from various chapters from PPP3
 *
 * Ch 11 Exes 01-03: Arrow, rectangle points, circle points, ellipse points
 *
 * Ch 11 Ex 09: Ellipse foci: I add an Improved_ellipse sublcass which can return its focal length,
 * its semi-latus rectum, and its ne/nw/se/sw points,
 * which are given as the points where the latus rectum meet the ellipse
 * This improved Ex 03, Ellipse points
 *
 *
 *
 * Ch 12 Ex 01: Smiley and frowny
 * Lots of possible improvements: see striped rectangle for not storing other drawn shapes as member ds
 * Ch 12 Ex 05: Striped Rectangle
 * Ch 12 Ex 06:
 * Ch 12 Ex 08:
 *
 *
 *
 */

#include <QtCore/qnamespace.h>

#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

#include "Arrow.h"
#include "ex02_rect_points.h"
#include "ex03_circle_ellipse_points.h"
#include "Frowny.h"
#include "Immovable_circle.h"
#include "Improved_ellipse.h"
#include "Smiley.h"
#include "Striped_rectangle.h"

using namespace Graph_lib;
using std::exception;

// Functions to demonstrate answers - see relevant class files
void ch11(Simple_window& win);
void ch12ex01(Simple_window& win);
void ch12ex04(Simple_window& win);
void ch12ex05(Simple_window& win);

int main()
{
    Application app;
    Simple_window win({20, 20}, 1000, 1000, "Main window");

    // ch11(win); // uncomment to run Ch 11 Exes 01-03 & 09
    // ch12ex01(win); // uncomment to run Ch 12 Ex 01
    // ch12ex05(win); // uncomment to run Ch 12 Ex 05
    Improved_ellipse e{Point{200, 200}, 10, 50};
    // win.attach(e);
    // double distance_between_focal_points = abs(e.focus1().x - e.focus2().x) + abs(e.focus1().y - e.focus2().y);
    cout << "Focal length (using my function): " << e.focal_length() << endl;

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
        Arrow arrow {centre(el),sw(el)};
        win.attach(arrow);
        // win.wait_for_button();
    }
    // Ch 11 Ex 09 Ellipse foci
    {
        // Draw a 300-by-200-pixel ellipse. Draw a 400-pixel-long x axis and a 300-pixel-long
        // y axis through the center of the ellipse. Mark the foci. Mark a point on the ellipse
        // that is not on one of the axes. Draw the two lines from the foci to the point.
        Improved_ellipse e{Point{400, 400}, 150, 100};
        int x_length = 400;
        int y_length = 300;
        Axis x{Axis::Orientation::x, Point{e.center().x - x_length / 2, e.center().y}, x_length,x_length / 20, "x"};
        Axis y{Axis::Orientation::y, Point{e.center().x, e.center().y + y_length / 2}, y_length,x_length / 20, "y"};
        // Manually move label
        x.label.move(58, -15);
        Mark m {Point{e.ne()}, 'x'};
        // Lines from foci to the point
        Line ftp1{m.point(0), e.focus1()};
        Line ftp2{m.point(0), e.focus2()};
        win.attach(e);
        win.attach(x);
        win.attach(y);
        win.attach(m);
        win.attach(ftp1);
        win.attach(ftp2);
        win.wait_for_button();
    }
}

void ch12ex01(Simple_window& win) {
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

void ch12ex04(Simple_window& win) {
    // ch12ex04 define a class Immovable_circle, inheriting from Circle
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

void ch12ex05(Simple_window& win){
    Striped_rectangle r{Point{200, 200}, 100, 150};
    win.attach(r);
    win.wait_for_button();
    r.move(50, 50);
    win.wait_for_button();
}