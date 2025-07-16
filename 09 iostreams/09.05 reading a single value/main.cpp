/*
 *Created by Orlando Shamlou on 2025/05/22
 *
 *This code follows §9.5 Reading a single value
 *Writing a 'get int within a range' function
 */

#include "../../PPP_support/PPPheaders.h"

int get10();

void skip_to_int();

int main()
{
    // while (true) {
        int user_input = get10();
        cout << user_input << " is an integer between 1 and 10 inclusive" << endl;
    // }
}


/*
 *Errors to deal with:
 *  Out of range
 *  no value (EOF)
 *  wrong type (not an int)
 * Options:
 *  Handle the problem in code
 *  Throw an exception
 *  Ignore
 */
int get10() {
    cout << "Please enter an integer in the range of 1 and 10 inclusive:" << endl;
    int n{0};
    while (true) {
        if (cin >> n) {
            if (n >=1 && n <=10) {
                return n;
            }
            cout << "Sorry, " << n << " is not in the [1:10] range, please try again:" << endl;
        }
        else {
            cout << "Sorry, enter an integer" << endl;
            skip_to_int();
        }
    }
    cout << cin.fail() << endl;
}

// Recover after reaching a 'bad' character
void skip_to_int() {
    if (cin.fail()) {
        // we found something that wasn't an integer
        cin.clear();                    // we'd like to look at the characters
        for (char ch; cin >> ch; ) {    // while we're able to extract characters from cin
            if (std::isdigit(ch)) {
                cin.unget();            // if it's a digit, put it back so we can read it (in the calling function)
                return;                 // job done
            }
        }
    }
    error("No input");              // eof or bad: give up
}

    }

}