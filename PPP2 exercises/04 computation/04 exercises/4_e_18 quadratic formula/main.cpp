#include <iostream>
using std::cin, std::cout, std::endl;
#include <string>
using std::string;
#include <cmath>
using std::pow, std::sqrt, std::isnan;
#include <vector>
using std::vector;

double get_double(string prompt);
vector<double> quadratic_formula(double a, double b, double c);

// Finds up to 2 solutions to the equation  ax2 + bx + c = 0
// Only finds real numbers
int main() {
    // Get and compute values
    double a = get_double("A: ");
    double b = get_double("B: ");
    double c = get_double("C: ");
    vector<double> results = quadratic_formula(a, b, c);
    cout << "Possible values: ";
    // Check for no solutions
    if (results.size() == 0)
    {
        cout << "None" << endl;
        return 1;
    }
    // Print solutions
    for (auto x : results)
    {
        if (!isnan(x))
        {
            cout << x << " ";
        }
    }
    cout << endl;
}

double get_double(string prompt)
{
    cout << prompt;
    double value;
    cin >> value;
    return value;
}

vector<double> quadratic_formula(double a, double b, double c)
{
    // Return 0, 1, or 2 solutions
    double x1 = (-b+(sqrt(pow(b, 2)-4*a*c)))/(2*a);
    double x2 = (-b-(sqrt(pow(b, 2)-4*a*c)))/(2*a);
    vector<double> results = {};
    // Only return valid solutions
    if (!isnan(x1))
    {
        results.push_back(x1);
    }
    // Don't return duplicate values
    if (!isnan(x2) && x2 != x1)
    {
        results.push_back(x2);
    }
    return results;
}
