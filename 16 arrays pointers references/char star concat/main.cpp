#include <iostream>

// Tests code from §16.3

// Concatenate c-style strings with '@' delimiter
char * concat(char* name, char* address)
{
    int name_size = strlen(name);
    int final_size = name_size + strlen(address) + 2; // +2 for '@' and terminating 0
    char* result = (char*) malloc(final_size);
    strcpy (result, name);
    result[name_size] = '@';
    strcpy(result+2, address);
    return result;
}

int main()
{
    std::cout << concat("Tav", "Faerun") << std::endl;
    return 0;
}