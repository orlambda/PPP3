//
// Created by Orlando Shamlou on 15/11/2024.
//

#ifndef DATE_H
#define DATE_H
#include <ostream>

class Date {
public:
    Date(int yy, int mm, int dd);
    void add_day(int n) {
    }
    int year() {return y;}
    int month() {return m;}
    int day() {return d;}
private:
    int y, m, d;
};

std::ostream& operator<<(std::ostream& os, Date d);

#endif //DATE_H
