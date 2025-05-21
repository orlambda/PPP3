//
// Created by Orlando Shamlou on 21/05/2025.
//
// This reimplements Name_age_pairs from Ex 02 using a Name_age_pair class
// instead of keeping names and ages in separate vectors.
//

#include "Name_age_pairs.h"
#include "../../PPP_support/PPPheaders.h"

int main()
{
    Name_age_pairs people{};

    people.add_pair(Name_age_pair{"zim", 30});
    people.add_pair(Name_age_pair{"Timma", 31});

    people.print();

    people.read_pairs();
    people.print();

    cout << "Sorting by name..." << endl;
    people.sort_by_name();
    people.print();

    cout << "Sorting by age..." << endl;
    people.sort_by_age();
    people.print();
}
