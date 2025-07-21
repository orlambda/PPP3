# PPP3
Exercises from Stroustrup's <em>Programming: Principles and Practice Using C++</em>, 3rd edition

This is my work which I am adding to as I progress through the book. My focus is on my own learning rather than providing a complete set of model answers for others to refer to. There are certain things I would like to come back to, such as reorganising the graphics chapters so each exercise has its own directory, and correcting stylistic inconsistencies, but I am prioritising moving through the book over perfecting the state of this repo. There are also bits of code lacking explanation which I used to test how language features work.

That said, I am open to discussing code, whether you've found a bug, have suggestions, or have a question.

I often opt not to use Stroustrup's support files for a few reasons:
- I'd rather not use `using namespace std;`
- I'd rather use `std::vector` than `ppp::vector`
- I'd rather use `throw runtime_error()` than `ppp::error()`
I keep the support files in a single folder so I don't need to duplicate them for each project. This means if you use my code without cloning the whole repo, you will need to change the path in the include directive in `main.cpp` to match wherever you keep the files.

I use [villevoutilainen/ProgrammingPrinciplesAndPracticeUsingQt](https://github.com/villevoutilainen/ProgrammingPrinciplesAndPracticeUsingQt) as a starter project for every exercise that uses Qt. I used `brew install qt` rather than Qt Creator.

A note for anyone who has struggled to get `import std;` to work: Your system may not fully support modules, or if it does, it may not be worth the time and effort to get it working as a beginner. Instead, use `#include <iostream>` and other standard library headers (you can use [cppreference.com](https://en.cppreference.com/) to find what header you need). Do read about what `import std;` does so you understand it if you see it in someone else's code and why it may be optimal when it's more widely supported.

If you're on macOS and are struggling to compile and debug using a recent version of C++, using [CLion](https://www.jetbrains.com/clion/) makes everything much easier.