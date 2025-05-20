//
// Created by Orlando Shamlou on 19/05/2025.
//

#ifndef NAME_PAIRS_H
#define NAME_PAIRS_H

#include <iostream>
#include <vector>

using namespace std;

class Name_pairs {
public:
    void add_pair(const string& name, double age);
    void read_names();
    void read_ages();
    void print() const;
    int entry_count() const;
    void sort_by_age();
    void sort_by_name();
    void check_equal_vector_lengths() const;
private:
    std::vector<std::string> names;
    std::vector<double> ages;
};

#endif //NAME_PAIRS_H
