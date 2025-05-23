/*
 *Created by Orlando Shamlou on 2025/05/23
 */

#include <format>

#include "../../PPP_support/PPPheaders.h"

// Manually adding right number of tabs is not ideal but not the point of this exercise
int main()
{
    int year = 2012;
    int age = 40;

    cout << "\t\t" << "hex" << "\t\t" << "oct" << "\t\t" << "dec" << "\t\t" << "bin" << endl;
    cout << "year:\t" << hex << year << "\t\t" << oct << year << "\t" << dec << year << "\t" << format("{:b}", year) << endl;
    cout << "year:\t" << hex << age << "\t\t" << oct << age << "\t\t" << dec << age << "\t\t" << format("{:b}", age) << endl;

    int age1{};
    int age2{};
    int age3{};

    // No error checking!
    cout << endl << "Input age in dec:" << endl;
    cin >> dec >> age1;
    cout << endl << "Input age in hex:" << endl;
    cin >> hex >> age2;
    cout << endl << "Input age in oct:" << endl;
    cin >> oct >> age3;
    cout << "Ages:" << "\t" << "dec" << "\t" << "hex" << "\t" "oct" << endl;
    cout << "\t\t" << age1 << "\t" << age2 << "\t" << age3 << "\t" << endl;
}