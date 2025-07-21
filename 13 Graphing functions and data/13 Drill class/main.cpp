// Created by Orlando Shamlou on 2025/07/18
// Following §13 Drill - Class definition

#include <iostream>
using std::cin, std::cout, std::istream, std::ostream, std::string;



bool contains(const string& test, const char& c)
{
    for (auto t: test)
    {
        if (t == c)
        {
            return true;
        }
    }
    return false;
}

bool contains(const string& test, const string& chars)
{
    for (auto c : chars)
    {
        if (contains(test, c))
        {
            return true;
        }
    }
    return false;
}


int min_age = 0;
int max_age = 149;
string illegal_chars = ":;\"'[]*&^%$#@!";

struct Person
{
    Person(string p_name="", int p_age=0) : n{p_name}, a{p_age}
    {
        if (p_age < min_age || p_age > max_age)
        {
            throw std::runtime_error("Invalid age");
        }
        if (contains(p_name, illegal_chars))
        {
            throw std::runtime_error("Invalid name");
        }
    }
public:
    string name() const {return n;}
    int age() const {return a;};

private:
    string n;
    int a;
};

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "{ " << p.name() << " , " << p.age() << " }\n";
}

istream& operator>>(istream&is, Person& p)
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    string name;
    int age;
    if (is >> ch1 >> name >> ch2 >> age >> ch3)
    {
        if (ch1 != '{' || ch2 != ',' || ch3 != '}')
        {
            is.clear(std::ios_base::failbit);
        } else
        {
            Person p_buffer = Person{name, age};
            p = p_buffer;
            // Bad:
            // R value doesn't have an address as not bound to a variable
            // Person* p_buffer = &Person{name, age};
            // && rvalue - used in move semantics (not a reference to a reference)
            // ... something(p_buffer);
            // p lives within this scope
            // p = &p_buffer;
            // obviously wrong:
            // int* a = &4;

        }
    }
    return is;
}

int main()
{
    Person goofy{"Goofy", 63};
    cout << goofy;

    Person p{"b",10};
    cin >> p;
    cout << p;
}