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

int get_size_of(std::array<int, 5> a)
{
    return sizeof(a);
}

int main()
{
    // On-stack array
    int a2[5];
    // Free-store-allocated
    int* a3 = new int[5];

    std::array<int, 5> std_arr{};

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
    cout << "Size of std::array of 5 ints: " << sizeof(std_arr) << endl;
    cout << "Size of std::array of 5 ints (other scope): " << get_size_of(std_arr) << endl;
    cout << "Number of elements in std::array (should be 5): " << sizeof(std_arr)/sizeof(std_arr[0]) << endl;

    return 0;
}