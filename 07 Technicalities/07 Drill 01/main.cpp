#include "../../PPP_support/PPPheaders.h"

// Does not swap
void swap_v(int a, int b);

void swap_r(int& a,int& b);


// Can not swap
//void swap_cr(const int& a, const int& b);



int main() {
    // Does not swap:
    int x = 7;
    int y = 9;
    swap_v(x, y);
    cout << "x (7): " << x << ", y (9): " << y << endl;
    // Cannot pass literal by reference
//    swap_r(7, 9);
    const int cx = 7;
    const int cy = 9;
    // swap_v does not modify const as passed by value
    swap_v(cx, cy);
    // cannot modify const
    //    swap_r(cx, cy);
    // Implicit conversion changes values
    swap_v(7.7,9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy);
    cout << "dx (7.7): " << dx << ", dy (9.9): " << dy << endl;
    swap_v(7.7,9.9);
}

void swap_v(int a,int b)
{
    int temp; temp=a; a=b; b=temp;
    cout << "x (7): " << a << ", y (9): " << b << endl;
}

void swap_r(int& a,int& b)
{
    int temp; temp = a, a=b; b=temp;
}

//void swap_cr(const int& a, const int& b)
//{
//    int temp; temp = a, a=b; b=temp;
//}