#include <iostream>
using std::cin, std::cout, std::endl, std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <numeric>
using std::accumulate;

int main() {
    cout << "Input lengths one by one (e.g. \"50 ft\")" << endl;
    double val;
    double val_in_m;
    string unit;
    vector<double> values;
    vector<string> units = {"cm", "m", "in", "ft"};
    // For each value-unit pair
    while (cin >> val >> unit)
    {
        // Convert to m
        int unit_index = -1;
        for (int i = 0; i < units.size(); ++i) {
            if (unit == units[i]) {
                unit_index = i;
                break;
            }
        }
        switch (unit_index)
        {
            // cm
            case 0:
                val_in_m = val/100;
                break;
            // m
            case 1:
                val_in_m = val;
                break;
            // in
            case 2:
                val_in_m = val/39.3701;
                break;
            // ft
            case 3:
                val_in_m = val/3.28084;
                break;
            default:
                cout << "invalid unit" << endl;
                continue;
        }
        cout << val_in_m << "m ";
        values.push_back(val_in_m);
        sort(values.begin(), values.end());
        double smallest = values[0];
        double largest = values[values.size()-1];
        if (val_in_m == smallest)
        {
            cout << "the smallest so far ";
        }
        if (val_in_m == largest)
        {
            cout << "the largest so far ";
        }

/*        {
            cout << "The smaller value is: " << values[0] << endl;
            cout << "The larger value is: " << values[1] << endl;
            if (values[0] / values[1] >= 0.99)
            {
                cout << "The numbers are almost equal." << endl;
            }
        }*/

    }
    cout << endl;
    cout << "Smallest: " << values[0] << " m" << endl;
    cout << "Largest: " << values[values.size()-1] << " m" << endl;
    cout << "Number of values: " << values.size() << endl;
    double sum = 0;
    for (auto v : values)
    {
        sum += v;
    }
    cout << "Sum of values: " << sum << " m" << endl;
}
