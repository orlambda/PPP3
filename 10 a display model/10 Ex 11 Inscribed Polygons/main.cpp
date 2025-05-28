// PPP3 Chapter 10 Exercise 11
// Inscribed regular polygons

// Horribly hard coded because problem is not solvable above pentagon
// Hexagon is sized and positioned manually

// Steps taken:
// Could not iteratively populate vector of Polygons - Polygons missing/bad copy constructor?
    // Use provided Vector_ref
// Calculated radii so that all Polygons have equal side lengths (so p3 fits in p4)
    // Not accurate for p5 and above - of course, as this would tend towards infinity as polygon tends towards a circle
// Move triangle down to inscribe it within the square
// Calculate pentagon position and radius based on square
    // Top of pentagon (if large enough) will always meet square vertices
// Manually place hexagon
// Possible improvements:
    // write more trig functions for finding sides and angles
    // Group code by function, improve naming, what angle, keep calculations to their own function or scope
    // Comment code clearly - what triangle are we working out
    // calculate position and size of hexagon but not important as pentagon can't be inscribed perfectly
    // look how to add polygons to a vector in a loop from 3 to max number of sides
        // the problem is Polygons don't seem to be copyable. could maybe use pointers, new/delete

#include <cmath>
#include <numbers>

#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

constexpr double pi = std::numbers::pi;

// TODO: name this function
Point point_from_centre (Point origin, double angle_in_radians, double radius);

void build_regular_pgon(Polygon& p, Point centre, int sides, double radius);
void build_regular_pgon(Polygon& p, Point centre, int sides, double radius, double rotation);

// might be useful?
double get_radius_from_side_length(int sides, double side_length);
double get_side_length_from_radius(int sides, double radius);

double radians_from_degrees(double d);

// TODO: trig functions - need better naming

double opposite_length_from_adj(double angle, double adj);
double hypotenuse_length_from_adj(double angle, double adj);

double hypotenuse_length(double leg_a, double leg_b);
double leg_length(double opp, double hyp);

using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[])
{
    Application app;
    Simple_window window({100, 100}, 900, 900, "Main window");
    Point origin{500, 500};


    // Polygon origin_pointer;
    // origin_pointer.add(origin);
    // origin_pointer.add(Point{origin.x+5, origin.y+10});
    // origin_pointer.add(Point{origin.x-5, origin.y+10});
    // window.attach(origin_pointer);

    // Circle origin_marker{origin, 2};
    // window.attach(origin_marker);

    double triangle_radius = 200;
    double triangle_side_length = get_side_length_from_radius(3, triangle_radius);

    // Base radius off of the triangle
    double square_radius = get_radius_from_side_length(4, triangle_side_length);
    double square_side_length = get_side_length_from_radius(4, square_radius);
    // Base radius off of the square
    // double pentagon_radius = get_radius_from_side_length(5, square_side_length);
    // Working out pentagon side length from the top right side, divided in two where it meets the square's vertex.
    // Upper side is the hypotenuse with angle 36 and adjacent square_side_length*0.5
    // Working for 36 for pentagon, sides n==5: 180 - (angle(n)*0.5) - angle(n-1)
        // unsure if (angle(n)*0.5) is correct for all polygons as inner polygon is a square
    double p5_side_upper = hypotenuse_length_from_adj(radians_from_degrees(36),square_side_length * 0.5);
    // Lower is side of a scalene triangle
    // We know square side length is opposite 108 degree angle
    double a_sin_A = square_side_length / sin(radians_from_degrees(108));
    // worked out all sides of the triange: 180 - 54(see above) - 108(pentagon angle) = 18
    // the side we want is opposite the angle 18, so p5_side_lower / sin(radians_from_degrees(18)) == a_sin_A;
    double p5_side_lower = a_sin_A * sin(radians_from_degrees(18));
    double pentagon_side_length = p5_side_upper + p5_side_lower;
    // work out pentagon radius from side length
    // splitting a pentagon from the centre to its vertices makes 5 isoceles triangles
    double apex_angle = radians_from_degrees(360.0 * 0.2);
    double base_angle = radians_from_degrees(108 * 0.5);
    // radius = leg length
    double base = pentagon_side_length;
    // base / sin(apex_angle) == leg / sin(base_angle)
    // base * sin(base_angle) / sin(apex_angle) == leg
    double leg = base * sin(base_angle) / sin(apex_angle);

    double pentagon_radius = leg;
    // double pentagon_side_length = get_side_length_from_radius(5, pentagon_radius);

    // Base radius off of the pentagon
    double hexagon_radius = get_radius_from_side_length(6, pentagon_side_length);
    // Manually fix size of hexagon
    hexagon_radius -= 22;
    // Find the radius of the square, based on the side length of triange

    // Default space between bottom of triangle and bottom of square
    double height_of_triangle = sqrt((pow(triangle_side_length, 2))-(pow((triangle_side_length * 0.5) , 2)));
    std::cout << height_of_triangle;
    double height_of_square = square_side_length;
    double height_of_bottom_part_of_triangle = sqrt((pow(triangle_radius, 2))-(pow((triangle_side_length * 0.5) , 2)));
    double height_of_top_bit_of_triangle = height_of_triangle - height_of_square * 0.5 - height_of_bottom_part_of_triangle;
    double space_between_p3_p4_bottoms = height_of_square - (height_of_triangle - height_of_top_bit_of_triangle);
    double p3p4b_default = space_between_p3_p4_bottoms;

    // Space we want between p3 p4 bottoms
    double p3p4b_wanted = height_of_square - height_of_triangle;

    // Finding the necessary height of the pentagon
    double p5_height_above_p4{};
    {
        double angle = radians_from_degrees(36);
        double adj = square_side_length * 0.5;
        p5_height_above_p4 = opposite_length_from_adj(angle, adj);
    }
    double height_of_bottom_part_of_pentagon = sqrt((pow(pentagon_radius, 2))-(pow((pentagon_side_length * 0.5) , 2)));
    double pentagon_height = pentagon_radius + height_of_bottom_part_of_pentagon;
    double p5_under_p4_wanted = pentagon_height - p5_height_above_p4 - square_side_length;
    double p5_under_p4_default = pentagon_height - pentagon_radius - (square_side_length * 0.5);

    Polygon triangle;
    build_regular_pgon(triangle, Point{origin.x,static_cast<int>(origin.y + p3p4b_default - p3p4b_wanted)}, 3, triangle_radius, ((2*pi/3/2)-pi/2));

    Polygon square;
    build_regular_pgon(square, origin, 4, square_radius, ((2*pi/4/2)-pi/2));

    Polygon pentagon;
    build_regular_pgon(pentagon, Point{origin.x,static_cast<int>(origin.y - p5_under_p4_default + p5_under_p4_wanted)}, 5, pentagon_radius, ((2*pi/5/2)-pi/2));

    // Manually move hexagon
    Polygon hexagon;
    build_regular_pgon(hexagon, Point{origin.x, origin.y - 37}, 6, hexagon_radius, ((2*pi/6/2)-pi/2));

    window.attach(triangle);
    window.attach(square);
    window.attach(pentagon);
    window.attach(hexagon);
    window.wait_for_button();
}

void build_regular_pgon(Polygon& p, Point centre, int sides, double radius) {
    build_regular_pgon(p, centre, sides, radius, 0);
}

void build_regular_pgon(Polygon& p, Point centre, int sides, double radius, double rotation) {
    double angle = rotation;
    for (int i = 0; i < sides; ++i) {
        p.add(point_from_centre(centre, angle, radius));
        angle += (2.0*pi)/sides;
    }
}

// This gives angle measuring anti-clockwise
// Use commented out line instead to measure clockwise
Point point_from_centre (Point origin, double angle_in_radians, double radius) {
    int x = static_cast<int>(cos(angle_in_radians) * radius);
    // int y = static_cast<int>((sin(angle_in_radians) * radius));
    int y = static_cast<int>(-(sin(angle_in_radians) * radius));
    return Point{x + origin.x, y + origin.y};
}

double get_side_length_from_radius(int sides, double radius) {
    double angle = (2.0*pi)/sides;
    return sqrt(radius*radius+radius*radius-(2*radius*radius*cos(angle)));
}

double get_radius_from_side_length(int sides, double side_length) {
    // Make a right-angled triangle and find the hypotenuse
    double angle = ((2*pi) / sides) * 0.5;
    double opp = side_length * 0.5;
    double hyp = opp / (sin(angle));
    return hyp;
}


double opposite_length_from_adj(double angle, double adj) {
    return tan(angle) * adj;
}

double hypotenuse_length_from_adj(double angle, double adj) {
    // cos(angle) == adj/hyp
    // cos(angle) * hyp == adj;
    // hyp == adj/cos(angle)
    return adj / cos(angle);
}

double radians_from_degrees(double d) {
    return d  * (pi / 180);
}