/*
 * Created by Orlando Shamlou on 2025/05/23
 * This follows PPP3 Chapter 09 Drill 11-17
 */


// #include "../../PPP_support/PPPheaders.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct Point {
    double x;
    double y;
};

// Read
istream& operator>>(istream& is, Point& p) {
    double d1, d2;
    char char1, char2, char3;
    is >> char1 >> d1 >> char2 >> d2 >> char3;
    if (!is) {
        return is;
    }
    if (char1 != '(' || char2 != ',' || char3 != ')') {
        is.clear(ios::failbit);
        return is;
    }
    p.x = d1;
    p.y = d2;
    return is;
}

// Write
ostream& operator<<(ostream& os, Point& p) {
    os << "(" << p.x << "," << p.y << ")";
    if (!os) {
        return os;
    }
    return os;
}

int main()
{
    std::vector<Point> points;
    cin.exceptions(cin.exceptions()|ios::badbit);
    // 7 is arbitrary (exercise specification)
    for (int i = 0; i < 7; ++i) {
        Point p{};
        cout << "Please enter a point: " << endl;
        cin >> p;
        if (!cin) {
            throw runtime_error("Error with input");
        }
        points.push_back(p);
    }
    // Open an ofstream and output each point to a file named mydata.txt.
    string name = "mydata";
    string suffix = ".txt";
    {
        ofstream ost {name + suffix};
        if (!ost)
            // ist is an input stream for the file named name
            throw runtime_error("can't open input file " + name + suffix);
        for (int i = 0; i < points.size(); ++i) {
            ost << points[i] << endl;
        }
    }

    std::vector<Point> processed_points;
    {
        ifstream ist {name + suffix};
        if (!ist) {
            throw runtime_error("can't open output file " + name + suffix);
        }
        Point p{};
        while (ist >> p) {
            processed_points.push_back(p);
        }
    }
    if (points.size() != processed_points.size()) {
        throw runtime_error("Vectors are different sizes");
    }
    for (int i = 0; i < points.size(); ++i) {
        if (points[i].x != processed_points[i].x
            || points[i].y != processed_points[i].y) {
            throw runtime_error("Vectors do not match");
        }
        cout << points[i] << endl;
        cout << processed_points[i] << endl;
    }
}
