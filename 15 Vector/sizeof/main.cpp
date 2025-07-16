#include <iostream>
#include <list>

using std::cin, std::cout, std::endl, std::list, std::vector;

int main()
{
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of int*: " << sizeof(int*) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of char*: " << sizeof(char*) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of vector of ints: " << sizeof(vector<int>(10)) << endl; // Not checking the size of the container
    cout << "Size of list of vectors of ints: " << sizeof(list<vector<int>>(4)) << endl; // Not checking the size of the container

    return 0;
}