
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

#include "Arrow.h"
#include "ex02_rect_points.h"

using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[])
{
    Application app;
    Simple_window win({20, 20}, 1000, 1000, "Main window");
    // Ex 01 Arrow
    {
        Text text({150, 20}, "Well hello there!");
        win.attach(text);
        Arrow arrow {Point{243,893}, Point{792, 20}};
        win.attach(arrow);
        arrow.set_color(Color::dark_cyan);
        // win.wait_for_button(); // uncomment to see this code
    }

    // Ex 02 Rectangle points
    {
        // see ex02_rect_points.h
        // Arrow to test code
        Rectangle rect{Point{0,0}, 100, 100};
        win.attach(rect);
        Arrow arrow {centre(rect), sw(rect)};
        win.attach(arrow);
        win.wait_for_button();
    }

}
