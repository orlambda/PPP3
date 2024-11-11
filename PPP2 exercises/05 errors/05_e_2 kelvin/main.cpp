// Converts a temperature between from ºC to K or vice versa

#include "../../include/std_lib_facilities.h"

double ctok(double c);
double ktoc(double k);

int main()
{
    char unit = ' ';
    while (unit != 'C' && unit != 'K')
    {
        // Prompt
        cout << "Select unit for temperature input (C/K): ";
        // cin.ignore(numeric_limits<streamsize>::max(),'\n');
        // cin.clear();
        cin >> unit;
    }
    cout << "Enter temperature in ";
    if (unit == 'C')
    {
        cout << "º";
    }
    cout << unit << " to convert: ";
    double temp_in = 0;
    cin >> temp_in;
    double temp_out;
    if (unit == 'C')
    {
        try {temp_out = ctok(temp_in);}
        catch (...) {error("Invalid temperature");}
    }
    else // unit is K
    {
        try {temp_out = ktoc(temp_in);}
        catch (...) {error("Invalid temperature");}
    }
    cout << temp_out;
    if (unit == 'C')
    {
        cout << "K" << endl;
    }
    else
    {
        cout << "ºC" << endl;
    }
}

double ctok(double c)
{
    if (c < -273.15)
    {
        error("Minimum temperature -273.15ºC");
    }
    double k = c + 273.15;
    return k;
}

double ktoc(double k)
{
    if (k < 0)
    {
        error("Minimum temperature 0K");
    }
    double c = k - 273.15;
    return c;
}