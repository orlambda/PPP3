//
// Created by Orlando Shamlou on 16/05/2025.
//

#include <iostream>

#include "my_chrono.h"
// #include "../../PPP_support/PPP_support.h"

namespace my_chrono {

// TODO: test if y{0} is OK or should be y{Year{0}}
my_chrono::Date::Date()
    :y{0}, m{1}, d{1} {
    if (!is_date(y, m, d)) {
        throw Invalid{};
    }
}

my_chrono::Date::Date (my_chrono::Year y, my_chrono::Month m, my_chrono::Day d)
    :y{y}, m{m}, d{d}{
    if (!is_date(y, m, d)) {
        throw Invalid{};
    }
}

void my_chrono::Date::add_day() {
    add_day(1);
}

void my_chrono::Date::add_day(int n) {
    for (int i = 0; i < n; ++i) {
        // if last day of year
        if (m == my_chrono::Month::dec && d == my_chrono::Day{31}) {
            ++y;
            d = my_chrono::Day{1};
            m = my_chrono::Month::jan;
        }
        // if last day of month (jan-nov)
        else if (d == last_day_of_month(m, is_leap_year(y))) {
            ++m;
            d = Day{1};
        }
        else {
            ++d;
        }
    }
}

my_chrono::Year my_chrono::Date::year() const {
    return y;
}

my_chrono::Month my_chrono::Date::month() const {
    return m;
}

my_chrono::Day my_chrono::Date::day() const {
    return d;
}

bool is_date(my_chrono::Year year, my_chrono::Month month, my_chrono::Day day) {
    // check for valid months
    if (month < my_chrono::Month::jan || month > my_chrono::Month::dec) {
        return false;
    }
    if (day < Day{1} || day > my_chrono::last_day_of_month(month, my_chrono::is_leap_year(year))){
        return false;
    }
    return true;
}

bool is_date(const my_chrono::Date& date) {
    return is_date(date.year(), date.month(), date.day());
}

bool is_leap_year(int year) {
    // Leap years are a multiple of 4, except for years evenly divisible by 100 but not by 400.
    // To be a leap year, the year number must be divisible by four – except for end-of-century years, which must be divisible by 400.
    // A leap year must be
    // divisible by four and not divisible by 100
    // return divisible by four and either not divisible by 100 or divisible by 400
    return !(year % 4) && ((year % 100) || !(year % 400));
}
bool is_leap_year(const my_chrono::Year& year) {
    return is_leap_year(year.y);
}

std::ostream& operator<<(std::ostream& os, my_chrono::Year year) {
    return os << year.y;
}

std::ostream& operator<<(std::ostream& os, my_chrono::Month month) {
    return os << static_cast<int>(month);
}

std::ostream& operator<<(std::ostream& os, my_chrono::Day day) {
    return os << day.d;
}

std::ostream& operator<<(std::ostream& os, my_chrono::Date date) {
    return os << date.year().y << "." << date.month() << "." << date.day().d;
}

bool operator==(const my_chrono::Year& a, const my_chrono::Year& b) {
    return a.y == b.y;
}

bool operator!=(const my_chrono::Year& a, const my_chrono::Year& b) {
    return !(a==b);
}

bool operator<(const my_chrono::Year& a, const my_chrono::Year& b) {
    return a.y < b.y;
}

bool operator<=(const my_chrono::Year& a, const my_chrono::Year& b) {
    return a.y <= b.y;
}

bool operator>(const my_chrono::Year& a, const my_chrono::Year& b) {
    return a.y > b.y;
}

bool operator>=(const my_chrono::Year& a, const my_chrono::Year& b) {
    return a.y >= b.y;
}

my_chrono::Year operator+(const my_chrono::Year& a, int b) {
    return my_chrono::Year{a.y + b};
}
my_chrono::Year operator-(const my_chrono::Year& a, int b) {
    return my_chrono::Year{a.y - b};
}

my_chrono::Year operator++(my_chrono::Year& y) {
    y = y + 1;
    return y;
}

my_chrono::Year operator--(my_chrono::Year& y) {
    y = y - 1;
    return y;
}

my_chrono::Month operator++(my_chrono::Month& m) {
    if (m == my_chrono::Month::dec) {
        m = my_chrono::Month::jan;
    } else {
        m = my_chrono::Month{static_cast<int>(m) + 1};
    }
    return m;
}

my_chrono::Month operator--(my_chrono::Month& m) {
    if (m == my_chrono::Month::jan) {
        m = my_chrono::Month::dec;
    } else {
        m = my_chrono::Month{static_cast<int>(m) - 1};
    }
    return m;
}

my_chrono::Month int_to_month(int x) {
    if (x < static_cast<int>(my_chrono::Month::jan) || x > static_cast<int>(my_chrono::Month::dec)) {
        //PPP::error("Invalid month");
    }
    return my_chrono::Month{x};
}

my_chrono::Day last_day_of_month(my_chrono::Month month,bool is_leap_year) {
    switch (month) {
        // February - deal with leap years
        case my_chrono::Month::feb:
            if (is_leap_year) {
                return my_chrono::Day{29};
            }
        return my_chrono::Day{28};
        // 31-day months
        case my_chrono::Month::jan:
        case my_chrono::Month::mar:
        case my_chrono::Month::may:
        case my_chrono::Month::jul:
        case my_chrono::Month::aug:
        case my_chrono::Month::oct:
        case my_chrono::Month::dec:
            return my_chrono::Day{31};
        // All others are 30
        default:
            return my_chrono::Day{30};
    }
}

bool operator==(const my_chrono::Day& a, const my_chrono::Day& b) {
    return a.d == b.d;
}

bool operator!=(const my_chrono::Day& a, const my_chrono::Day& b) {
    return !(a==b);
}

bool operator<(const my_chrono::Day& a, const my_chrono::Day& b) {
    return a.d < b.d;
}

bool operator<=(const my_chrono::Day& a, const my_chrono::Day& b) {
    return a.d <= b.d;
}

bool operator>(const my_chrono::Day& a, const my_chrono::Day& b) {
    return a.d > b.d;
}

bool operator>=(const my_chrono::Day& a, const my_chrono::Day& b) {
    return a.d >= b.d;
}

my_chrono::Day operator+(const my_chrono::Day& a, int b) {
    return my_chrono::Day{a.d + b};
}

my_chrono::Day operator-(const my_chrono::Day& a, int b) {
    return my_chrono::Day{a.d + b};
}

my_chrono::Day operator++(my_chrono::Day& y) {
    y = y + 1;
    return y;
}

my_chrono::Day operator--(my_chrono::Day& y) {
    y = y - 1;
    return y;
}

bool operator==(const my_chrono::Date& a, const my_chrono::Date& b) {
    return (
        a.year() == b.year()
        && a.month() == b.month()
        && a.day() == b.day()
        );
}

bool operator!=(const my_chrono::Date& a, const my_chrono::Date& b) {
    return !(a==b);
}

bool operator<(const my_chrono::Date& a, const my_chrono::Date& b) {
    if (!is_date(a) || !is_date(b)) {
        //PPP::error("Invalid year");
    }
    // Year is less
    if (a.year() < b. year()) {
        return true;
    }
    // Year is equal
    if (a.year() == b.year()) {
        // Month is less
        if (a.month() < b. month()) {
            return true;
        }
        // Month is equal
        if (a.month() == b. month()) {
            if (a.day() < b. day()) {
                return true;
            }
        }
    }
    return false;
}

bool operator<=(const my_chrono::Date& a, const my_chrono::Date& b) {
    return a < b || a == b;
}

bool operator>(const my_chrono::Date& a, const my_chrono::Date& b) {
    return b < a;
}

bool operator>=(const my_chrono::Date& a, const my_chrono::Date& b) {
    return a > b || a == b;
}

// TODO:
my_chrono::Date add_years(const my_chrono::Date& date, int years) {
    auto new_year = date.year();
    auto new_month = date.month();
    auto new_day = date.day();
    if (new_month == my_chrono::Month::feb && new_day == my_chrono::Day{29} && is_leap_year(new_year)) {
        new_month = my_chrono::Month::mar;
        new_day = my_chrono::Day{1};
    }
    return my_chrono::Date{new_year, new_month, new_day};
}

// TODO:
my_chrono::Date add_months(const my_chrono::Date& date, int months) {
    return my_chrono::Date{};
}

my_chrono::Date add_days(const my_chrono::Date& date, int days) {
    my_chrono::Date new_date = date;
    new_date.add_day((days));
    return new_date;
}
}




//
// enum class Day_of_week {
//     monday, tuesday, wednesday, thursday, friday, saturday, sunday
//     };
//
// bool is_date(my_chrono::Year year, my_chrono::Month month, my_chrono::Day day) {
//     // Incomplete check - max day is 31 for any month
//     if (year.y < 0
//         || month < my_chrono::Month::jan || month > my_chrono::Month::dec
//         || day.d < 1 || day.d > 31 ) {
//         return false;
//     }
//     return true;
// }
//
// bool is_leap_year(const my_chrono::Year& year) {
//     // Leap years are divisible by 4
//     // TODO: add 100, 400 etc
//     return !(year.y % 4);
// }
//
// bool is_leap_year(int year) {
//     return is_leap_year(my_chrono::Year{year});
// }
//
// bool operator==(const my_chrono::Year& a, const my_chrono::Year& b) {
//     return a.y == b.y;
// }
//
// bool operator!=(const my_chrono::Year& a, const my_chrono::Year& b) {
//     return !(a==b);
// }
//
// my_chrono::Year operator+(const my_chrono::Year& a, int b) {
//     return my_chrono::Year{a.y + b};
// }
//
// my_chrono::Year operator-(const my_chrono::Year& a, int b) {
//     return my_chrono::Year{a.y - b};
// }
//
// my_chrono::Year operator++(my_chrono::Year& y) {
//     ++y.y;
//     return y;
// }
//
// my_chrono::Year operator--(my_chrono::Year& y) {
//     --y.y;
//     return y;
// }
// my_chrono::Month operator++(my_chrono::Month& m) {
//     m = (m== my_chrono::Month::dec) ? my_chrono::Month::jan : my_chrono::Month{static_cast<int>(m)+1};
//     return m;
// }
//
// my_chrono::Month operator--(my_chrono::Month& m) {
//     m = (m== my_chrono::Month::jan) ? my_chrono::Month::dec : my_chrono::Month{static_cast<int>(m)-1};
//     return m;
// }
//
// my_chrono::Month int_to_month(int x) {
//     return my_chrono::Month{x};
// }
//
// bool operator==(const Day& a, const Day& b) {
//     return a.d == b.d;
// }
//
// bool operator!=(const my_chrono::Day& a, const my_chrono::Day& b) {
//     return !(a==b);
// }
//
// my_chrono::Day operator+(const Year& a, int b) {
//     return Year{a.y + b};
// }
//
// my_chrono::Year operator-(const Year& a, int b) {
//     return Year{a.y - b};
// }
//
// bool operator==(const Date& a, const Date& b) {
//     if (a.day() != b.day()
//         || a.month() != b.month()
//         || a.year() != b.year()
//         ) {
//         return false;
//     }
//     return true;
// }
//
//
//
//
// my_chrono::Date::Date()
//     :y{0}, m{0}, d{0}
// {
//     std::cout << "Made a date!" << std::endl;
// }
//
// my_chrono::Date::Date(my_chrono::Year p_y, my_chrono::Month p_m, my_chrono::Day p_d)
//     :y{p_y.y}, m{p_m}, d{p_d.d}
// {
//     // TODO: add validity check!!!
//     if (!true) {
//         throw Invalid{};
//     }
//     std::cout << "Made a date!" << std::endl;
// }
//
// void my_chrono::Date::add_day() {
//     add_day(1);
// }
//
// void my_chrono::Date::add_day(int n) {
//
// }
//
// my_chrono::Year my_chrono::Date::year() const {
//     return Year{y.y};
// }
//
// my_chrono::Month my_chrono::Date::month() const {
//     return m;
// }
//
// my_chrono::Day my_chrono::Date::day() const {
//     return Day{d.d};
// }
