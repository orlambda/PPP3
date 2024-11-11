// Question: ctrl-d / cmd-d - not terminating stream but terminating process

#include <iostream>
#include <vector>
using std::cin, std::cout, std::endl, std::string, std::vector;

int main() {
    vector<string> banned_words {"asparagus", "behemoth"};
    cout << "Enter text:" << endl;
    // For each word in text
    for (string current_word; cin >> current_word; )
    {
        // Check if word is banned
            // Check every banned_word in banned_words
            // If it is, banned = true and stop searching
        bool banned = false;
        for (auto banned_word : banned_words)
        {
            if (banned_word == current_word)
            {
                banned = true;
                break;
            }
        }
        // If word is banned, output BLEEP, else output word
        if (banned)
        {
            cout << "BLEEP ";
        }
        else
        {
            cout << current_word << " ";
        }
    }
    cout << endl << "Thank you! ";
}
