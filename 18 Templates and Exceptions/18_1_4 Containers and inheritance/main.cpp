#include <iostream>
using std::cout, std::endl, std::vector;

// QUESTION: how to prevent slicing of Derived when adding to vector<Base>?
// delete Base's special functions or make them protected

struct Derived;
struct Base
{
public:
    Base() = default;
    // Either:
        // ...
        // public:
            // Base(Base const&) = delete;
            // Base& operator=(Base const&) = delete;
    // Or:
        // ...
        protected:
            Base(Base const&) = default;
            Base(Base&&) = default;
            Base& operator=(Base const&) = default;
            Base& operator=(Base&&) = default;
};

struct Derived : Base {int a = 1;};

int main()
{
    vector<Base> vb;
    vector<Derived> vd;
    // vb = vd; // error
    // vd = vb; // error
    Base b;
    Derived d;
    vb.push_back(d); // error
    // int a = vb[0].a; // error - Derived has been sliced (if we allow slicing and added to vector successfully)
}