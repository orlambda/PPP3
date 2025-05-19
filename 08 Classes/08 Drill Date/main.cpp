//
// Created by Orlando Shamlou
//

#include <chrono>
#include <iostream>

#include "my_chrono.h"
#include "../../PPP_support/PPPheaders.h"

using namespace my_chrono;

int main() {
    // Drill
    Date today{Year{2020}, Month::feb, Day{2}};
    Date tomorrow = today;
    tomorrow.add_day();
    cout << "Today is " << today << " and tomorrow is " << tomorrow <<"." << endl;
}

