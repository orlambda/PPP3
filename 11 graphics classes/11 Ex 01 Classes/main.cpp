
#include "PPP/Window.h"
#include "PPP/Graph.h"

#include "Arrow.h"

using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[])
{
    Application app;
    Window win({20, 20}, 1000, 1000, "Main window");
    Text text({150, 20}, "Well hello there!");
    win.attach(text);
    Arrow arrow {Point{243,893}, Point{792, 20}};
    win.attach(arrow);
    arrow.set_color(Color::dark_cyan);
    app.gui_main();
}
