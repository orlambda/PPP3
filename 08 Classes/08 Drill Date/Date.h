//
// Created by Orlando Shamlou on 14/05/2025.
//

#ifndef DATE_H
#define DATE_H



class Date {
public:
    class Invalid {};
    Date(int y, int m, int d);
    void add_day(int n);
    int year();
    int month();
    int day();
    bool is_valid();
private:
    int y, m, d;
};

enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

enum class Day {
    monday, tuesday, wednesday, thursday, friday, saturday, sunday
    };

#endif //DATE_H
