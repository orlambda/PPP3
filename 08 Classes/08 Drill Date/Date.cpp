//
// Created by Orlando Shamlou on 14/05/2025.
//

#include "Date.h"
#include <iostream>

Date::Date(int p_y, int p_m, int p_d)
    :y{p_y}, m{p_m}, d{p_d}
{
    if (!is_valid()) {
        throw Invalid{};
    }
    std::cout << "Made a date!" << std::endl;
}

void Date::add_day(int n) {
}

int Date::year() {
    return y;
}

int Date::month() {
    return m;
}

int Date::day() {
    return d;
}

bool Date::is_valid() {
    return 0 < m && m < 13;
}
