// Created by Orlando Shamlou on 2025/07/17

// Following PPP3 §15.7.1

// Testing for an error in the book's code

#include <iostream>
using std::cin, std::cout, std::string;

struct Link {
    Link(const string& v, Link* p = nullptr, Link* s = nullptr)
    : value{v}, prev{p}, succ{s} { }
    string value;
    Link* prev;
    Link* succ;
};

// move n positions in list; return nullptr for "not found"
// positive n moves forward, negative backward
Link* advance(Link* p, int n) {
    if (p==nullptr)
        return nullptr;
    while (0<n) {
        --n;
        if (p->succ)
            p = p->succ;
        return nullptr;
    }
    while (n<0) {
        ++n;
        if (p->prev)
            p = p->prev;
        return nullptr;
    }
    return p;
}

int main()
{
    Link* norse_gods = new Link{"Thor",nullptr,nullptr};
    norse_gods = new Link{"Odin",nullptr,norse_gods};
    norse_gods->succ->prev = norse_gods;
    norse_gods = new Link{"Freja",nullptr,norse_gods};
    norse_gods->succ->prev = norse_gods;
    Link* current = norse_gods;
    current = advance(current, 2);
    current = advance(current, -2);
    cout << current->value;
}