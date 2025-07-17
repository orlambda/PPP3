// Testing if std::span has range checking on my system (no)
// Following §16.4.1

#include <iostream>
#include <span>

// Function taken from §16.4.1
void test(std::span<int> s)
{
    std::cout << "size: " << s.size() << '\n';
    for (int x : s)
        std::cout << x << '\n';
    try {
        int y = s[s.size()];
    }
    catch (...) {
        std::cout << "we have range checking\n";
        return;
    }
    std::cout << "no range checking! Boo Hoo!\n";
    std::terminate(); // exit the program
}

int main()
{
    int a[]{1, 2, 3, 4, 5};
    std::span s {a, 2};
    test(s);
    return 0;
}