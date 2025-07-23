// Following PPP3 §17.5.2

#include <iostream>
using std::cin, std::cout, std::endl, std::string, std::vector;

struct X
{
    int val;
    void out(const string& s, int nv)
    {
        // Tell the user what function has been called
        cout << this << "->" << s << ": " << val << "(" << nv << ")" << endl;
    }
    X() {out("X()",0); val = 0;} // default constructor
    explicit X(int x) {out("X(int)",x); val=x;}
    X(const X& x) {out("X(X&) ",x.val); val=x.val;}  // copy constructor
    // X(X&& x){out("X(X&&) ",x.val); val=x.val; x.val=0;} // move constructor
    X& operator=(const X& x) {out("X copy assignment",x.val); val=x.val; return *this;} // copy assignment
    // X& operator=(X&& x) {out("X move assignment",x.val); val=x.val; x.val=0; return *this;} // move assignment
    ~X() { out("˜X()",0);} // destructor
};

X test_x{1};

X copy(X a)
{
    cout << "copy()" << endl;
    return a;
}
X copy2(X a)
{
    cout << "copy2()" << endl;
    X aa = a;
    return aa;
}
X& ref_to(X & a)
{
    cout << "ref_to()" << endl;
    return a;
}
X* make(int i)
{
    cout << "make()\n";
    X a(i);
    return new X(a);
}
struct XX {
    X a;
    X b;
};

int main()
{

    X loc {4}; // local variable
    X loc2 {loc}; // copy construction
    loc = X{5}; // copy assignment
    loc2 = copy(loc); // call by value and return
    loc2 = copy2(loc);
    X loc3 {6};
    X& r = ref_to(loc); // call by reference and return
    delete make(7);
    delete make(8);
    vector<X> v(4); // default values
    XX loc4;
    X* p = new X{9}; // an X on the free store
    delete p;
    X* pp = new X[5]; // an array of Xs on the free store
    delete[] pp;

}

