/*
 *Created by Orlando Shamlou on 2025/05/28
 *Following PPP3 §11 Drill
 */

// #include <filesystem>

#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[]) {
    Application app;
    // Make an 1000x800 Simple_window (exercise says 800x1000, I think in error)
    int win_w = 1000;
    int win_h = 800;
    Simple_window win({100, 100}, win_w, win_h, "Main window");
    // Make an 8x8 grid of 100x100 squares
    Vector_ref<Rectangle> grid;
    // Number of squares per grid
    int grid_w = 8;
    int grid_h = 8;
    int grid_square_w = 100;
    int grid_square_h = 100;
    // For 8 rows
    for (int i = 0; i < grid_w; ++i) {
        // For 8 columns
        for (int j = 0; j < grid_h; ++j) {
            // Make a 100x100 rectangle, using unique_ptr (§18.5.2) for unnamed object
            int w = grid_square_w;
            int h = grid_square_h;
            grid.push_back(make_unique<Rectangle>(Point{i*w, j*h},w, h));
            win.attach(grid[grid.size()-1]);
        }
    }
    // Color red all rectangles diagonally from top left
    // Check w and h to allow non-square grids
    for (int i = 0; i < grid_w && i < grid_h; ++i) {
        // grid[i * grid_h] is the top square in each row, add i to down 1 each row
        grid[i*grid_h+i].set_fill_color(Color::dark_red);
    }
    string directory = std::filesystem::current_path();
    // Place three copies of an image on the grid, each with a 200x200 mask, without obscuring red squares.
    Vector_ref<Image> trees;
    for (int i = 0; i < 3; ++i) {
        int im_x = (i * 200) % win_w;
        int im_y = ((i * 200) + 400) % win_h;
        trees.push_back(make_unique<Image>(Point{im_x, im_y}, directory + "/tree.jpeg"));
        trees[trees.size()-1].set_mask(Point{im_x, im_y}, 200, 200);
        win.attach(trees[trees.size()-1]);
    }
    // Add a 100x100 image that moves around the grid
    // from square to square, left to right and top to bottom, looping back to top left.
    Image moving_im{Point{0,0}, directory + "/tree.jpeg"};
    moving_im.set_mask(Point{1000,1000}, 100, 100);
    win.attach(moving_im);
    while (true) {
        // Test if move sets positions or transforms relatively
        win.wait_for_button();
        Point current_point = moving_im.point(0);
        Point velocity{0,0};
        if (!(current_point.x + grid_w > grid_w * grid_square_w - grid_square_w)) {
            velocity.x = grid_square_w;
        } else {
            velocity.x = - (grid_w * grid_square_w - grid_square_w);
            if (!(current_point.y + grid_h > grid_h * grid_square_h - grid_square_h)) {
                velocity.y = grid_square_h;
            } else {
                velocity.y = - (grid_h * grid_square_h - grid_square_h);
            }
        }

        moving_im.move(velocity.x, velocity.y);
    }



}
