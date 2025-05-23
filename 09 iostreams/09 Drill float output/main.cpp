#include <iomanip>

#include "../../PPP_support/PPPheaders.h"

int main() {
    double n =1234567.89;
    // The most precise is fixed due to precision
    cout << "defaultfloat: " << defaultfloat << n << endl;
    cout << "fixed: " << fixed << n << endl;
    cout << "scientific: " << scientific << n << endl;

    cout << endl;

    // The most precise are defaultfloat and scientific
    cout << setprecision(12) << "defaultfloat: " << defaultfloat << n << endl;
    cout << "fixed: " << fixed << n << endl;
    cout << "scientific: " << scientific << n << endl;

    cout << endl;

    // All have floating point errors
    cout << setprecision(20) << "defaultfloat: " << defaultfloat << n << endl;
    cout << "fixed: " << fixed << n << endl;
    cout << "scientific: " << scientific << n << endl;
}
