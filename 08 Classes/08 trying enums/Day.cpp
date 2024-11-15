//
// Created by Orlando Shamlou on 15/11/2024.
//

#include "Day.h"

std::ostream& operator<<(std::ostream& os, Day d) {
    return os << static_cast<int>(d); }

Day operator++(Day& d) {
    return (d == Day::sunday) ? Day::monday : Day{static_cast<int>(d) + 1}; }