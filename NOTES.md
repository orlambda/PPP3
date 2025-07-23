## TODO

### Today

#### Reading
Re-read
17.5.1, 17.5.2

#### Exercises

#### Other
p499 try this

### Files to check/redo?
- 09 iostreams/09 09.10.01 integer dec hex output/main.cpp
- 09 iostreams/09 Ex 01 read write file lowercase/cmake-build-debug/input.txt
- 09 iostreams/09 Ex 01 read write file lowercase/main.cpp
- 11 graphics classes/11 Ex 01 Classes/CMakeLists.txt
- 11 graphics classes/11 Ex 01 Classes/main.cpp

### Exercises to come back to
#### §10
(12)
#### §12
Drill (again)
(7)
#### §13
Drill
2, 3, 4, 11
#### §14
Drill
1, 2, 3, 4, (5), 6, 7, (10)

### Read / re-read
Window.h

## Notes
### §13

§13.4
    draw() vs draw_specifics()
    compare with smiley

§13.6.3 scaling
    check p403 loop and work backwards

### §14

An action defined in our program that is invoked by the system in response to some user-action (e.g., "clicking" a button) is call a callback


### §17

#### §17.5.1 - Explicit constructors

A constructor with a single parameter defines a conversion from its parameter type to its class.


vector<int> v1{3}; // ok
vector<int> v2(3); // ok - considered explicit - creates a vector 3 ints
vector<int> v3 = 3; // odd
v3 = 10; // odd - assigns a new vector of 20 ints

void f(vector<int>& v){}
f(10); // calls f with a new vector of 10 ints

class Vector {
    // ...
    explicit Vector(int); // prevents implicit int-to-Vector conversion
}

Vector v1 = 1; // error - implicit
Vector v2(10); // ok - explicit
f(10); // error - implicit
f(Vector(10)); // ok - explicit