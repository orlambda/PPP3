// Following §16.5.1

#include <iostream>
#include <span>

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

bool is_palindrome(const char* first, const char* last)
// first points to the first letter, last to the last letter
{
    while (first < last) { // we haven’t reached the middle
        if (*first!=*last)
            {return false;}
        ++first; // move forward
        --last; // move backward
    }
    return true;
}

bool is_palindrome(std::span<char> s)
{
    return (s.size()? is_palindrome(s.data(), s.data()+s.size()) : true);
}

int main()
{
    std::cout << "Is empty string a palindrome?: " << is_palindrome("") << std::endl;
    std::cout << "Is \"i\" a palindrome?: " << is_palindrome("i") << std::endl;
    std::cout << "Is \"ha\" a palindrome?: " << is_palindrome("ha") << std::endl;
    char char_arr[]{"hah"};
    std::cout << "Is \"hah\" a palindrome?: " << is_palindrome(&char_arr[0], &char_arr[2]) << std::endl;
    std::span spn {char_arr};
    std::cout << "Is \"hah\" a palindrome?: " << is_palindrome(spn) << std::endl;
    return 0;
}