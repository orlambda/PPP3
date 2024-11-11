#include "../../include/std_lib_facilities.h"

int main() {
    try {
        // No need to store in vector
        vector<int> fib_series{1, 1};
        for (int i = 1; true; ++i) {
            int next = fib_series[i - 1] + fib_series[i];
            if (next < fib_series[i]) {
                break;
            }
            fib_series.push_back(next);
        }
        cout << " " << fib_series[fib_series.size() - 1];
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }

}
