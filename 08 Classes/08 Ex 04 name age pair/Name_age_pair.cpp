//
// Created by Orlando Shamlou on 21/05/2025.
//

#include "Name_age_pair.h"

    Name_age_pair::Name_age_pair(const string& name, double age) : n{name}, a{age} {
        // TODO: research appropriate exceptions
        if (age < 0) {
            throw std::runtime_error("Age must be at least 0");
        }
        if (age > 200) {
            throw std::runtime_error("Age must be less than 200");
        }
        if (name.empty()) {
            throw std::runtime_error("Name must not be blank");
        }
    }
    string Name_age_pair::name() const {
        return n;
    }
    double Name_age_pair::age() const {
        return a;
    }