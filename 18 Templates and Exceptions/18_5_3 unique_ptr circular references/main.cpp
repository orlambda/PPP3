// Created by Orlando Shamlou on 2025/07/25
// Following §18.5.3 Unique Pointer

// Output:
// Constructing a
// Constructing b
// Destructing b
// Destructing a
// Destructing b
// Destructing a

#include <iostream>
using std::cout, std::endl, std::shared_ptr, std::string;

struct Slink
{
    string name;
    shared_ptr<Slink> next;
    Slink(string s, shared_ptr<Slink> sp) : name{s}, next{sp}
    {
        cout << "Constructing " << name << endl;
    }
    ~Slink()
    {
        cout << "Destructing " << name << endl;
    }
};

int main()
{
    Slink a{"a", nullptr};
    Slink b{"b", std::make_shared<Slink>(a)};
    a.next = std::make_shared<Slink>(b);
}