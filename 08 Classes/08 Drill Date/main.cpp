#include "Date.h"
#include "../../PPP_support/PPPheaders.h"

ostream& operator<<(ostream& os, Date date) {
    return os << date.year() << "." << date.month() << "." << date.day() << endl; }

int main() {
    enum nothing {
        hey, hi
    };
    std::cout << "Hello, World!" << std::endl;
    Date someDate{1, 2, 3};
    std::cout << someDate << endl;
    Month m2 = Month::feb;
    int m2int = static_cast<int>(Month::feb);
    std::cout << m2int << endl;
    m2int = static_cast<int>(m2);
    std::cout << m2int << endl;
    std::cout << static_cast<int>(Month::jan) << endl;
    // No error checking in place for valid months
    Month m13 = Month{13};
    std::cout << static_cast<int>(m13) << endl;
}

