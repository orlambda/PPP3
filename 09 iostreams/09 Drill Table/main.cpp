#include <iomanip>

#include "../../PPP_support/PPPheaders.h"

// Print a table of people and their information
// Does not format check (e.g. email and phone)
// Could be improved by checking people for longest string in each field and sizing to fit

struct Person {
    string last_name;
    string first_name;
    string email_address;
    string telephone_number;
};

void add_people(vector<Person>& people);
void print_record(const Person& person);

int main()
{
    vector<Person> people;

    add_people(people);

    cout << "| " << setw(30) << "NAME" << " | " << setw(35) << "EMAIL" << " | " << setw(20) << "TELEPHONE" << " |" << endl;

    for (const auto& person : people) {
        print_record(person);
    }
}

// Ugly code - not the point of this exercise
void add_people(vector<Person>& people) {
    Person person;
    person.last_name = "Biggs";
    person.first_name = "Humphrey";
    person.email_address = "big_humph@mail.com";
    person.telephone_number = "+77030948098";
    people.push_back(person);

    person.last_name = "Shmakwofiwueoi";
    person.first_name = "Todd Lwegwp";
    person.email_address = "todd_oieogeproipoweipfwefq@mail.com";
    person.telephone_number = "+1232111118";
    people.push_back(person);

    person.last_name = "Jo";
    person.first_name = "Sam";
    person.email_address = "jo_sam@mail.com";
    person.telephone_number = "+1703034480";
    people.push_back(person);

    person.last_name = "Hophophophophophop";
    person.first_name = "Flop";
    person.email_address = "fp@mail.com";
    person.telephone_number = "+4479502948532234";
    people.push_back(person);

    person.last_name = "Erikson";
    person.first_name = "Erik";
    person.email_address = "hidadimdad@mail.com";
    person.telephone_number = "+1123409854";
    people.push_back(person);
}

void print_record(const Person& person) {
    cout
        << "| " << setw(30) << person.last_name + ", " + person.first_name
        << " | " << setw(35) << person.email_address
        << " | " << setw(20) << person.telephone_number
        << " |" << endl;
}
