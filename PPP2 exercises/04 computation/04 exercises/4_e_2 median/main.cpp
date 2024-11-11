#include <iostream>
using std::cin, std::cout, std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

int main() {
    // prompt user
    cout << "Enter temperatures (terminate with '|': ";
    // make vector of sorted temperatures
    vector<double> temps;
    for (double temp; cin >> temp; )
    {
        temps.push_back(temp);
    }
    sort(temps.begin(), temps.end());
    // quit if no temps
    if (temps.empty())
    {
        cout << "No temperatures inputted." << endl;
        return 1;
    }
    // compute median
    // compute middle value(s)
    // alternatively for odd-sized vectors, use middle value and skip computing mean
    long mid_index1 = static_cast<int>(temps.size() / 2);
    long mid_index2 = static_cast<int>((temps.size() - 1) / 2);
    // median is mean of middle values
    double median = (temps[mid_index1] + temps[mid_index2]) / 2;
    cout << "Median is " << median << endl;
    // compute median working out
    /*even:
    0 1
    average(0 1)
    2/2 = 1
    2-1 2 = 0.5 = 0
    0 1 2 3
    average(1, 2)
    4/2 = 2
    4-1/2 = 1.5

    odd
    0 1 2
    average (1 1)
    3/2 = 1.5
    3-1/2 = 1
    0
    average (0 0)
    1/2 = 0.5
    1-1/2 = 0*/
}
