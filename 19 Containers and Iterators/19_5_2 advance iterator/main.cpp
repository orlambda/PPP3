// Created by Orlando Shamlou on 2025/07/25
// Following PPP3 §19_5_2

// Rewrite advance so it will move backwards if given a negative argument

#include <iostream>

// TODO
template<std::forward_iterator Iter>
void advance(Iter& p, int n)
{
    while (0<n) {
        ++p;
        --n;
    }
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}