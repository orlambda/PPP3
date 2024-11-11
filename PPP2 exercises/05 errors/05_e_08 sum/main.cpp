#include "../../include/std_lib_facilities.h"

int main() {
    try {
        cout << "Please enter the number of values you want to sum: ";
        int n = -1;
        // QUESTION: is the !(cin >> n) test condition necessary/useful?
        if (!(cin >> n) or n < 1) {
            error("Must input positive integer for number of values to sum.");
        }
        cout << "Please enter some integers (press '|' to stop): ";
        vector<int> values;
        int x;
        while (cin >> x) {
            values.push_back(x);
        }
        if (n > values.size()) {
            error("Not enough integers entered to sum.");
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += values[i];
        }
        cout << "The sum of the first " << n << " numbers ( ";

        for (int i = 0; i < n; ++i) {
            cout << values[i] << " ";
        }
        cout << ") is " << sum << "." << endl;
    }
    catch (runtime_error e) {
        cout << e.what() << endl;
        keep_window_open("~");
    }
}
