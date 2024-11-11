// Converts a temperature between from ºC to K or vice versa

#include "../../include/std_lib_facilities.h"

double ctof(double c);
double ftoc(double f);

int main()
{
    char unit = ' ';
    while (unit != 'C' && unit != 'F')
    {
        // Prompt
        cout << "Select unit for temperature input (C/F): ";
        // cin.ignore(numeric_limits<streamsize>::max(),'\n');
        // cin.clear();
        cin >> unit;
    }
    cout << "Enter temperature in " << "º" << unit << " to convert: ";
    double temp_in = 0;
    cin >> temp_in;
    double temp_out;
    if (unit == 'C')
    {
        try {temp_out = ctof(temp_in);}
        catch (...) {error("Invalid temperature");}
    }
    else // unit is F
    {
        try {temp_out = ftoc(temp_in);}
        catch (...) {error("Invalid temperature");}
    }
    cout << temp_out;
    if (unit == 'C')
    {
        cout << "ºF" << endl;
    }
    else
    {
        cout << "ºC" << endl;
    }
}

double ctof(double c)
{
    if (c < -273.15)
    {
        error("Minimum temperature -273.15ºC");
    }
    double f = c * (9.0/5) + 32;
    return f;
}

double ftoc(double f)
{
    if (f < -459.67)
    {
        error("Minimum temperature -459.67F");
    }
    double c = (f - 32) * (5.0/9);
    return c;
}