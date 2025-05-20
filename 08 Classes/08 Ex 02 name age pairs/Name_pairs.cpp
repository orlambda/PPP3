//
// Created by Orlando Shamlou on 19/05/2025.
//

#include <iostream>

#include "Name_pairs.h"

using namespace std;

void Name_pairs::add_pair(const string& name, double age) {
    names.push_back(name);
    ages.push_back(age);
}
void Name_pairs::read_names() {
    string name;
    // TODO: allow spaces
    cout << "Enter names, '.' to quit:" << endl;
    while (cin) {
        std::getline(cin, name);
        if (name == ".") {
            break;
        }
        names.push_back(name);
    }
}

void Name_pairs::read_ages() {
    double age;
    // TODO: enter '.' to quit
    cout << "Enter names, '-1' to quit:" << endl;
    while (cin) {
        cin >> age;
        if (age == -1) {
            break;
        }
        if (age < 0) {
            throw std::runtime_error("Age should be 0 or above");
        }
        ages.push_back(age);
    }
}

void Name_pairs::print() const {
    for (int i = 0; i < names.size(); ++i) {
        cout << "Name: " << names[i] << ", Age: " << ages[i] << endl;
    }
}

int Name_pairs::entry_count() const {
    check_equal_vector_lengths();
    return static_cast<int>(names.size());
}

void Name_pairs::sort_by_age() {
    check_equal_vector_lengths();
    int entries = entry_count();
    for (int i = 0; i < entries; ++i) {
        // Find index of highest age - don't bother with last entries
        int index_of_highest_age = i;
        double highest_age = ages[i];
        for (int j = i; j < entries; ++j) {
            if (ages[j] > highest_age) {
                highest_age = ages[j];
                index_of_highest_age = j;
            }
        }
        // Remove name and age from that index
        string name_buffer = names[index_of_highest_age];
        double age_buffer = ages[index_of_highest_age];
        names.erase(names.begin() + index_of_highest_age);
        ages.erase(ages.begin() + index_of_highest_age);
        names.insert(names.begin(), name_buffer);
        ages.insert(ages.begin(), age_buffer);
    }
}

void Name_pairs::sort_by_name() {
    check_equal_vector_lengths();
    int entries = entry_count();
    for (int i = 0; i < entries; ++i) {
        // Find index of highest age - don't bother with last entries
        int index_of_highest_name = i;
        string highest_name = names[i];
        for (int j = i; j < entries; ++j) {
            if (names[j] > highest_name) {
                highest_name = names[j];
                index_of_highest_name = j;
            }
        }
        // Remove name and age from that index
        string name_buffer = names[index_of_highest_name];
        double age_buffer = ages[index_of_highest_name];
        names.erase(names.begin() + index_of_highest_name);
        ages.erase(ages.begin() + index_of_highest_name);
        names.insert(names.begin(), name_buffer);
        ages.insert(ages.begin(), age_buffer);
    }
}

void Name_pairs::check_equal_vector_lengths() const {
    if (ages.size() != names.size()) {
        throw std::runtime_error("Names and ages have different number of entries");
    }
}