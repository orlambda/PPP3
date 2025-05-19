// QUESTION: If the compiler ignores whitespace why do I need quote marks before and after a line break in a long string?
// QUESTION: Does clion have preferences so line breaks are added in the Run window for long strings?

#include <iostream>
using std::string, std::cin, std::cout, std::endl;

inline void simple_error(string s);

// Produces a simple form letter based on user input
int main() {
    // 0. Prompts
    cout << "Enter the first name of the person you want to write to: ";
    string first_name;
    cin >> first_name;
    cout << "What is " << first_name << "'s age? ";
    int age;
    cin >> age;
    if (age <= 0 || age >= 110)
    {
        simple_error("You're kidding!");
    }
    cout << "Enter the first name of another friend: ";
    string friend_name;
    cin >> friend_name;
    char friend_pronouns = 0;
    cout << "What are " << friend_name << "'s pronouns? (h = he/him, s = she/her, t = they/them) ";
    cin >> friend_pronouns;

    // 1. Greet user
    cout << endl << endl << "Dear " << first_name << "," << endl;
    // 2. Add introductory lines
    cout << "\tHow are you? I am well. I have ordered a burger and chips and eagerly await its delivery. "
            "I have just put a jar of gherkins in the fridge and will add a single leaf of lettuce to the burger myself rather than paying extra. "
            "I have salt and vinegar, and mustard if I feel like it. I do not have ketchup. "
            "I decided I would rather write this code than cook. I'm writing extra text so it fills up a few lines." << endl;
    // 3. Prompt the user for the name of another friend, and store it in friend_name
    cout << "\tHave you seen " << friend_name << " recently? ";
    // 4. Friend's pronouns

    if (friend_pronouns == 'h' || friend_pronouns == 'H')
    {
        cout << "If you see him please ask him to call me." << endl;
    }
    else if (friend_pronouns == 's' || friend_pronouns == 'S')
    {
        cout << "If you see her please ask her to call me." << endl;
    }
    else
    {
        cout << "If you see them please ask them to call me." << endl;
    }
    // 5. Friend's age
    cout << "\t";
    if (age < 12)
    {
        cout << "Next year you will be " << age + 1 << ". ";
    }
    if (age == 17)
    {
        cout << "Next year you will be able to vote. ";
    }
    if (age > 70)
    {
        cout << "I hope you are enjoying retirement. ";
    }
    cout << "It's funny how quickly time passes. " << endl;
    cout << endl << "Yours sincerely," << endl << endl << endl << "O." << endl;
}

inline void keep_window_open()
{
    cin.clear();
    cout << "Please enter a character to exit\n";
    char ch;
    cin >> ch;
    return;
}

inline void keep_window_open(string s)
{
    if (s == "") return;
    cin.clear();
    cin.ignore(120, '\n');
    for (;;) {
        cout << "Please enter " << s << " to exit\n";
        string ss;
        while (cin >> ss && ss != s)
            cout << "Please enter " << s << " to exit\n";
        return;
    }
}

// error function to be used (only) until error() is introduced in Chapter 5:
inline void simple_error(string s)	// write ``error: s and exit program
{
    std::cerr << "error: " << s << '\n';
    keep_window_open();		// for some Windows environments
    exit(1);
}

