#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[]) {
    Application app;
    Simple_window window({220, 220}, 600, 600, "Main window");

    // Exercises 1-2
    {
        // rectangle blue
        Rectangle blue_rect{Point{100, 100},200,50};
        blue_rect.set_color(Color::blue);

        // polygon_rectangle red
        Polygon red_poly_rect;
        red_poly_rect.add(Point{200,200});
        red_poly_rect.add(Point{400,200});
        red_poly_rect.add(Point{400,250});
        red_poly_rect.add(Point{200,250});
        red_poly_rect.set_color(Color::red);

        // Draw a 100-by-30 Rectangle and place the text ‘‘Howdy!’’ inside it.
        Point howdy_origin{300,100};
        Rectangle howdy_box{howdy_origin, 100, 30};
        Text howdy_text{Point{howdy_origin.x + 30,howdy_origin.y},"Howdy"};

        // window.attach(blue_rect);
        // window.attach(red_poly_rect);
        // window.attach(howdy_box);
        // window.attach(howdy_text);
        // window.wait_for_button();
    }

    // Exercise 3
    {
        Polygon o_outer;
        o_outer.add(Point{200, 100});
        o_outer.add(Point{220, 120});
        o_outer.add(Point{220,230});
        o_outer.add(Point{200, 250});
        o_outer.add(Point{180, 230});
        o_outer.add(Point{180, 120});

        Polygon o_inner;
        o_inner.add(Point{200, 110});
        o_inner.add(Point{210, 130});
        o_inner.add(Point{210,220});
        o_inner.add(Point{200, 240});
        o_inner.add(Point{190, 220});
        o_inner.add(Point{190, 130});


        Polygon s;
        s.add(Point{260, 100});
        s.add(Point{280, 115});
        s.add(Point{250, 135});
        s.add(Point{280, 225});
        s.add(Point{250, 250});
        s.add(Point{230, 235});
        s.add(Point{260, 215});
        s.add(Point{230, 125});
        // s.add(Point{180, 30});

        o_outer.set_style(Line_style(Line_style::solid, 4));
        o_inner.set_style(Line_style(Line_style::solid, 4));
        s.set_style(Line_style(Line_style::solid, 4));

        o_outer.set_color(Color::cyan);
        o_inner.set_color(Color::cyan);
        s.set_color(Color::dark_magenta);

        o_outer.set_fill_color(Color::dark_blue);
        o_inner.set_fill_color(Color::dark_yellow);
        s.set_fill_color(Color::dark_red);

        Image copter {Point{100,50}, "/Users/orlandoshamlou/Downloads/kirby.jpg"};
        window.attach(copter);
        window.set_label("Mars copter");

        window.attach(o_outer);
        window.attach(o_inner);
        window.attach(s);
        window.wait_for_button();


    }

    {

    }

    window.wait_for_button();


}
