//
// Created by Orlando Shamlou on 15/11/2024.
//

#ifndef DAY_H
#define DAY_H

#include <iostream>

// Scoped enum
enum class Day {
    monday, tuesday, wednesday, thursday, friday, saturday, sunday};

std::ostream& operator<<(std::ostream& os, Day d);

Day operator++(Day& d);

#endif //DAY_H
