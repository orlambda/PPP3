#include "Smiley.h"
#include "PPP/Simple_window.h"
#include "PPP/Graph.h"

using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[])
{
    Application app;
    Simple_window window({20, 20}, 600, 400, "Main window");
    Text text({150, 20}, "Well hello there!");
    window.attach(text);

    Smiley c{Point{100,100}, 100};

    window.attach(c);

    window.wait_for_button();
    c.move(400, 400);
    window.wait_for_button();
}
