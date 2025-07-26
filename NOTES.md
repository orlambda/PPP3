## TODO

### Today

### Misc
- Add to ERRORS.md
    - from commits
- Organise graphics chapters
    - Move Qt and graph_lib to parent folder
    - Move each exercise to its own directory / main.cpp
- p592: for (auto p = lst.end(); p!=lst::begin(); −−p) cout << ∗p << '\n'; are these 1 too high? can you check for p<lst::begin()?

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
#### §19
p571 write match()

### Read / re-read
Window.h
§18.4(.4)
§20.6.4-drill

### Files to check/redo?
- 09 iostreams/09 09.10.01 integer dec hex output/main.cpp
- 09 iostreams/09 Ex 01 read write file lowercase/cmake-build-debug/input.txt
- 09 iostreams/09 Ex 01 read write file lowercase/main.cpp
- 11 graphics classes/11 Ex 01 Classes/CMakeLists.txt
- 11 graphics classes/11 Ex 01 Classes/main.cpp

## Notes

### §13 Graphing Functions and Data

§13.4
    draw() vs draw_specifics()
    compare with smiley

§13.6.3 scaling
    check p403 loop and work backwards

### §14 GUI

An action defined in our program that is invoked by the system in response to some user-action (e.g., "clicking" a button) is call a callback


### §17 Essential Operations

#### §17.5.1 - Explicit constructors

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

### 18 Templates
The process of generating types (classes) from a class template given template arguments is called specialization or template instantiation.
For example, Vector<char> and Vector<Open_polyline*> are said to be specializations of Vector.

A constructor with a single parameter defines a conversion from its parameter type to its class.

Concept: a set of requirements on a set of template arguments.

T::value_type: see https://stackoverflow.com/questions/44571362/what-is-the-use-of-value-type-in-stl-containers

## Questions
19_2_1 (p554): why can't `high()` be assigned to `jill_high`? my ugly solution - or use `auto`? is the problem with the code the leak if `delete[] jack_data;` is never reached? is the solution wrapping jack_data in a class - would I need to implement ALL operations?

p524: should `space==0` be `space!=0`? why 8? will calling this repeatedly keep increasing the ratio of uninitialised to initialised space?
p524: why does `Vector<T,A>::resize()` call `destroy()` but not `alloc.deallocate()`, like in `Vector<T,A>::reserve()`?
I think because `reserve()` deallocates the space with `delete` (§17.8.2). but why is `destroy()` necessary? does `reserve()` not already destroy those objects, and if not, does it not need to?
p536, Vector::operator=() (second version): why not `return *this` after destroying elements?
 
with a destructor that delete its data?
p558: `curr` is private, does it need a public method to get its data? what about `*this==*b`?
p559: The standard-library vector doesn’t provide push_front(). Why not? Implement push_front() for vector and compare it to push_back().'
    Is this because a vector's contents are stored in an array, and pushing to the front would require moving every element in the array?

p592: "The difference between an input iterator and a forward iterator is that you can traverse a sequence repeatedly using a forward iterator." What does this mean?

p609: What is a better way? 

p622: void print same - print_same?