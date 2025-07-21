#include <iostream>


class C
{
public:
    C() {std::cout << 1 << std::endl;};
    C(int n) {std::cout << n << std::endl;};
    int i1;
protected:
    int number() {return i2;}
private:
    int i2;
};

// Assumes private: all members inherited as private
// Caps the level all inherited members will be
// Public and protected will be
class C1 : C
{
public:
    // Always calls a constructor of the base class
    // Assumes default constructor (no parameters)
    C1() : C() {std::cout << "2" << std::endl;}
    int get_i1() {return i1;}
    int get_i2() {return number();}
protected:
private:
};

class C2 : protected C
{
public:
protected:
private:
};

class C3 : public C
{
    // Private because this is a class - unaffected by public keyword as not inherited
    int n;
public:
protected:
private:
};

struct C4 : private C
{
    // Public because struct
    int z;
    // Inherited members will cap at private
};

int main()
{
    // C c0{20};
    // bad: c0.number();

    C1 c{};
    int a = c.get_i1();
    // std::cout << a << std::endl;

}