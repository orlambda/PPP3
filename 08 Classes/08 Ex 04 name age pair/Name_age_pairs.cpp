//
// Created by Orlando Shamlou on 21/05/2025.
//

#include "Name_age_pairs.h"

#include <iostream>

using namespace std;

void Name_age_pairs::add_pair(const Name_age_pair& pair) {
    pairs.push_back(pair);
}

void Name_age_pairs::read_pairs() {
    // TODO: improve input format
    string name;
    cout << "Enter name, '.' to quit:" << endl;
    while (cin >> name) {
        if (name == ".") {
            return;
        }
        cout << "Enter age:" << endl;
        double age;
        cin >> age;
        pairs.push_back(Name_age_pair{name , age});
        cout << "Enter name, '.' to quit:" << endl;
    }
}

void Name_age_pairs::print() const {
    for (int i = 0; i < pairs.size(); ++i) {
        cout << "Name: " << pairs[i].name() << ", Age: " << pairs[i].age() << endl;
    }
}

int Name_age_pairs::entry_count() const {
    return static_cast<int>(pairs.size());
}

void Name_age_pairs::sort_by_age() {
    int entries = entry_count();
    for (int i = 0; i < entries; ++i) {
        // Find index of highest age - don't bother with last entries
        int index_of_highest_age = i;
        double highest_age = pairs[i].age();
        for (int j = i; j < entries; ++j) {
            if (pairs[j].age() > highest_age) {
                highest_age = pairs[j].age();
                index_of_highest_age = j;
            }
        }
        // TODO: Swap entries instead of resizing vector
        // TODO: use stl sort algorithm with iterators
        // Remove name and age from that index
        string name_buffer = pairs[index_of_highest_age].name();
        double age_buffer = pairs[index_of_highest_age].age();
        pairs.erase(pairs.begin() + index_of_highest_age);
        pairs.insert(pairs.begin(), Name_age_pair{name_buffer, age_buffer});
    }
}

void Name_age_pairs::sort_by_name() {
    int entries = entry_count();
    for (int i = 0; i < entries; ++i) {
        // Find index of highest age - don't bother with last entries
        int index_of_highest_name = i;
        string highest_name = pairs[i].name();
        for (int j = i; j < entries; ++j) {
            if (pairs[j].name() > highest_name) {
                highest_name = pairs[j].name();
                index_of_highest_name = j;
            }
        }
        // TODO: Swap entries instead of resizing vector
        // TODO: use stl sort algorithm with iterators
        // Remove name and age from that index
        string name_buffer = pairs[index_of_highest_name].name();
        double age_buffer = pairs[index_of_highest_name].age();
        pairs.erase(pairs.begin() + index_of_highest_name);
        pairs.insert(pairs.begin(), Name_age_pair{name_buffer, age_buffer});
    }
}