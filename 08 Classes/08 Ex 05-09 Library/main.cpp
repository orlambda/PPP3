

#include <chrono>
#include <iostream>

#include "Book.h"
#include "Patron.h"

using namespace chrono;
using namespace std;

int main()
{
    Book my_book{"123412341230X", "Dictionary", "Humans",
        year_month_day{year{2012}, month{12}, day{01}}, Book::Genre::nonfiction, 1};
    cout << my_book << endl;
    cout << my_book.is_available() << endl;
    cout << "Checking out copy!" << endl;
    my_book.check_out();
    cout << my_book.is_available() << endl;
    cout << "Adding copy!" << endl;
    my_book.add_copy();
    cout << my_book.is_available() << endl;
    Patron me{"Orlando", 123, 1};
    cout << owes_fee(me) << endl;
    me.set_fee(0);
    cout << owes_fee(me) << endl;
}
