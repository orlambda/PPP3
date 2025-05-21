//
// Created by Orlando Shamlou on 21/05/2025.
//

#ifndef NAME_AGE_PAIRS_H
#define NAME_AGE_PAIRS_H

#include <vector>

#include "Name_age_pair.h"

using namespace std;

class Name_age_pairs {
public:
    void add_pair(const Name_age_pair& pair);
    void read_pairs();
    void print() const;
    int entry_count() const;
    void sort_by_age();
    void sort_by_name();
private:
    vector<Name_age_pair> pairs;
};


#endif //NAME_AGE_PAIRS_H
