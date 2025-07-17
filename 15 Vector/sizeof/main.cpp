#include <iostream>
#include <list>

using std::cin, std::cout, std::endl, std::list, std::vector;

// § 15 and 16

// Static array
int a1[5];

int get_size_of(int p[])
{
    return sizeof(p);
}

int main()
{
    // On-stack array
    int a2[5];
    // Free-store-allocated
    int* a3 = new int[5];

    cout << "Sizes using sizeof()" << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of int*: " << sizeof(int*) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of char*: " << sizeof(char*) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of vector of ints: " << sizeof(vector<int>(10)) << endl;
    cout << "Size of list of vectors of ints: " << sizeof(list<vector<int>>(4)) << endl;
    cout << "Size of static array of 5 ints: " << sizeof(a1) << endl;
    cout << "Size of static array of 5 ints (other scope): " << get_size_of(a1) << endl;
    cout << "Size of on-stack array of 5 ints: " << sizeof(a2) << endl;
    cout << "Size of on-stack array of 5 ints (other scope): " << get_size_of(a2) << endl;
    cout << "Size of dynamic array of 5 ints: " << sizeof(*a3) << " !!" << endl;
    cout << "Number of elements in array (should be 5): " << sizeof(a1)/sizeof(a1[0]) << endl;

    return 0;
}