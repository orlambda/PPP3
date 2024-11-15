//
// Created by Orlando Shamlou on 15/11/2024.
//

#include "Date.h"
#include <stdexcept>

Date::Date(int yy, int mm, int dd)
    :y{yy},m{mm},d{dd}
{
    // Very incomplete date validity checks
    if (yy < 1 || mm < 1 || dd < 1) {throw std::runtime_error("Date: values must be at least 1");}
    if (yy > 20000 || mm > 12 || dd > 31) {throw std::runtime_error("Date: value too high");}
}