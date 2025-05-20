#include "Name_pairs.h"
#include "../../PPP_support/PPPheaders.h"

int main()
{
    Name_pairs people{};

    people.add_pair("Tim", 30);
    people.add_pair("Timma", 31);

    people.print();

    people.read_names();
    people.read_ages();
    people.print();

    cout << "Sorting by name..." << endl;
    people.sort_by_name();
    people.print();

    cout << "Sorting by age..." << endl;
    people.sort_by_age();
    people.print();
}
