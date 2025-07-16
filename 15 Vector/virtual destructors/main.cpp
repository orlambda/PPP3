#include <iostream>

// Created on 2025/07/17 by Orlando Shamlou
// Follows PPP3 §15.5.2


using std::cout, std::endl;

class Base1
{
public:
    Base1() { cout << "Constructor called for Base1" << endl; }
    ~Base1() { cout << "Destructor called for Base1" << endl; }
private:
};

class Derived1 : Base1
{
public:
    Derived1() { cout << "Constructor called for Derived1" << endl; }
    ~Derived1() { cout << "Destructor called for Derived1" << endl; }
private:
};

class Base2
{
public:
    Base2() { cout << "Constructor called for Base2" << endl; }
    ~Base2() { cout << "Destructor called for Base2" << endl; }
private:
    Base1 member_Base1{};
};

class Derived2 : Base2
{
public:
    Derived2()
    {
        cout << "Constructor called for Derived2" << endl;
        member_Derived1 = new Derived1;
    }
    ~Derived2()
    {
        cout << "Destructor called for Derived2" << endl;
        delete member_Derived1;
    }
private:
    Derived1* member_Derived1;
};


int main()
{
    // Base b1{};
    // Base* b2 = new Base; // destructor is not called
    Derived2 d2_1{};
    return 0;
}