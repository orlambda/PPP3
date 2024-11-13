#include "../../PPP_support/PPPheaders.h"

namespace X
{
    int var;
    void print(){
        cout << var << endl;
    }
}
namespace Y
{
    int var;
    void print(){
        cout << var << endl;
    }
}

namespace Z
{
    int var;
    void print(){
        cout << var << endl;
    }
}

int main() {
    X::var = 7;
    X::print(); // print X’s var
    using namespace Y;
    var = 9;
    print(); // print Y’ svar
    {
        using Z::var;
        using Z::print;
        var = 11;
        print(); // print Z’ svar
    }
    print(); // print Y's var
    X::print(); // print X's var
}
