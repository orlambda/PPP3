//
// Created by Orlando Shamlou on 16/05/2025.
//

#ifndef MYCHRONO_H
#define MYCHRONO_H

namespace my_chrono {

// Note: Year and Day are very similar and could inherit from the same struct/class
struct Year {
    int y;
};
enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
struct Day {
    int d;
};
enum class Day_of_week {
    monday, tuesday, wednesday, thursday, friday, saturday, sunday
};

class Date {
public:
    class Invalid {};
    Date();
    Date(my_chrono::Year y, my_chrono::Month m, my_chrono::Day d);
    void add_day();
    void add_day(int n);
    my_chrono::Year year() const;
    my_chrono::Month month() const;
    my_chrono::Day day() const;
private:
    my_chrono::Year y;
    my_chrono::Month m;
    my_chrono::Day d;
};

bool is_date(my_chrono::Year year, my_chrono::Month month, my_chrono::Day day);
bool is_date(const my_chrono::Date& date);
bool is_leap_year(int year);
bool is_leap_year(const my_chrono::Year& year);



bool operator==(const my_chrono::Year& a, const my_chrono::Year& b);
bool operator!=(const my_chrono::Year& a, const my_chrono::Year& b);
bool operator<(const my_chrono::Year& a, const my_chrono::Year& b);
bool operator<=(const my_chrono::Year& a, const my_chrono::Year& b);
bool operator>(const my_chrono::Year& a, const my_chrono::Year& b);
bool operator>=(const my_chrono::Year& a, const my_chrono::Year& b);
my_chrono::Year operator+(const my_chrono::Year& a, int b);
my_chrono::Year operator-(const my_chrono::Year& a, int b);
my_chrono::Year operator++(my_chrono::Year& y);
my_chrono::Year operator--(my_chrono::Year& y);

my_chrono::Month operator++(my_chrono::Month& m);
my_chrono::Month operator--(my_chrono::Month& m);

Month int_to_month(int x);
my_chrono::Day last_day_of_month(my_chrono::Month month,bool is_leap_year);

std::ostream& operator<<(std::ostream& os, my_chrono::Year year);
std::ostream& operator<<(std::ostream& os, my_chrono::Month month);
std::ostream& operator<<(std::ostream& os, my_chrono::Day day);
std::ostream& operator<<(std::ostream& os, my_chrono::Date date);

bool operator==(const my_chrono::Day& a, const my_chrono::Day& b);
bool operator!=(const my_chrono::Day& a, const my_chrono::Day& b);
bool operator<(const my_chrono::Day& a, const my_chrono::Day& b);
bool operator<=(const my_chrono::Day& a, const my_chrono::Day& b);
bool operator>(const my_chrono::Day& a, const my_chrono::Day& b);
bool operator>=(const my_chrono::Day& a, const my_chrono::Day& b);
my_chrono::Day operator+(const my_chrono::Day& a, const int b);
my_chrono::Day operator-(const my_chrono::Day& a, const int b);
my_chrono::Day operator++(my_chrono::Day& y);
my_chrono::Day operator--(my_chrono::Day& y);

bool operator==(const my_chrono::Date& a, const my_chrono::Date& b);
bool operator!=(const my_chrono::Date& a, const my_chrono::Date& b);
bool operator<(const my_chrono::Date& a, const my_chrono::Date& b);
bool operator<=(const my_chrono::Date& a, const my_chrono::Date& b);
bool operator>(const my_chrono::Date& a, const my_chrono::Date& b);
bool operator>=(const my_chrono::Date& a, const my_chrono::Date& b);
my_chrono::Date add_years(const my_chrono::Date& date, const int years);
my_chrono::Date add_months(const my_chrono::Date& date, const int months);
my_chrono::Date add_days(const my_chrono::Date& date, const int days);

}

#endif //MYCHRONO_H
