// Following §16.5.1

#include <iostream>

bool is_palindrome(const std::string& s)
{
    int first = 0; // index of first letter
    int last = s.length()-1; // index of last letter
    while (first < last) { // we haven’t reached the middle
        if (s[first]!=s[last])
            {return false;}
        ++first; // move forward
        --last; // move backward
    }
    return true;
}

int main()
{
    std::cout << "Is empty string a palindrome?: " << is_palindrome("") << std::endl;
    std::cout << "Is \"i\" a palindrome?: " << is_palindrome("i") << std::endl;
    std::cout << "Is \"ha\" a palindrome?: " << is_palindrome("ha") << std::endl;
    return 0;
}