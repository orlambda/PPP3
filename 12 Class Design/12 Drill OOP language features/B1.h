//
// Created by Orlando Shamlou on 29/05/2025.
//

#ifndef B1_H
#define B1_H

#include <iostream>

using namespace std;

class B1 {
protected:
    // B1(); // compilation error with no derived classes
public:
    virtual void pvf() = 0;
    // virtual ~B1(); // compilation error with no derived classes
    virtual void vf() {
        cout << "B1::vf()" << endl;
    }
    virtual void f() {
        cout << "B1::f()" << endl;
    }
};

// Defining subclass
// Derive a class D1 from B1 and override vf().
class D1 : public B1 {
public:
    void vf() override {
        cout << "D1::vf()" << endl;
    }
    void f() override {
        cout << "D1::f()" << endl;
    }
    void pvf() override {
        cout << "D1::pvf()" << endl;
    }
};

// Define a class D2 derived from D1 and override pvf() in D2.
class D2 : public D1 {
public:
    void pvf() override {
        cout << "D2::pvf()" << endl;
    }
};

/*
*Define a class B2 with a pure virtual function pvf(). Define a class D21 with a string data
member and a member function that overrides pvf(); D21::pvf() should output the value of the
string. Define a class D22 that is just like D21 except that its data member is an int. Define a
function f() that takes a B2& argument and calls pvf() for its argument. Call f() with a D21 and
a D22.
 */

class B2 {
public:
    virtual void pvf() = 0;
};

class D21 : public B2 {
public:
    void pvf() override {
        cout << s << endl;
    }
private:
    string s = "D21 string";
};

class D22 : public B2 {
public:
    void pvf() override {
        cout << i << endl;
    }
private:
    int i = 22;
};

void f(B2& b2) {
    b2.pvf();
}

#endif //B1_H
