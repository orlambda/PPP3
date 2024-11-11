#include "../../include/std_lib_facilities.h"
int main() {
    try {
        const vector<string> real_days
                {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday",
                 "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday",
                 "mon", "tue", "tues", "wed", "weds", "thu", "thur", "thurs", "fri", "sat", "sun"};
        vector<string> days;
        vector<int> values;
        string day;
        int value;
        int rejection_count = 0;
        cout << "Enter pairs of days and numbers, terminating with '| |' (e.g. Tuesday 3 Wednesday 4 |): ";
        while (cin >> day >> value) {
            // Check day
            bool acceptable_day = false;
            for (auto x: real_days) {
                if (day == x) {
                    acceptable_day = true;
                    break;
                }
            }
            if (acceptable_day) {
                days.push_back(day);
                values.push_back(value);
            } else {
                ++rejection_count;
            }

        }
        int sum = 0;
        for (auto x: values) {
            sum += x;
        }
        cout << "Sum of accepted values: " << sum << endl
        << "Size of day and value vectors: " << days.size() << " and " << values.size() << endl
        << "Number of rejected inputs: " << rejection_count
        ;
    }
    catch (runtime_error e)
    {
        cout << e.what();
        return 1;
    }
}
