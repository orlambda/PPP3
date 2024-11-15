#include "../../PPP_support/PPPheaders.h"
#include "Day.h"

// Plain enum
enum Month {
    january, february, march, april, may, june,
    july, august, september, october, november, december};

int main()
{
    // Testing how enums work
    cout << Day::monday << endl; // 0
    cout << static_cast<int>(Day::monday) << endl; // 0
    constexpr int today = static_cast<int>(Day::monday);
    cout << today << endl; // 0
    Day fakesday {7};
    cout << static_cast<int>(fakesday) << endl; // 7
    Day monday2 {Day::monday};
    Day sunday2 {6};
    cout << (sunday2 == Day::sunday) << endl; // true
    cout << (++sunday2 == Day::monday) << endl; // true
    // cout << static_cast<int>(Day::fakesday); // error
}
