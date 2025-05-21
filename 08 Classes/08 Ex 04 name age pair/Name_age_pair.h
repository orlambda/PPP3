//
// Created by Orlando Shamlou on 21/05/2025.
//

// This class represents a name and an age. The values can not be changed after constructions.

#ifndef NAME_AGE_PAIR_H
#define NAME_AGE_PAIR_H

#include <iostream>
using namespace std;

class Name_age_pair {
public:
    Name_age_pair(const string& name, double age);
    string name() const;
    double age() const;
private:
    string n;
    double a;
};

#endif //NAME_AGE_PAIR_H
