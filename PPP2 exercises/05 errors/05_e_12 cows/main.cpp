#include "../../include/std_lib_facilities.h"

int main() {
    try {
        while (true) {
            // Start game
            cout << "Starting new Bulls and Cows game\n";
            cout << "Enter seed: ";
            int seed = 0;
            cin >> seed;
            seed_randint(seed);
            vector<int> numbers{};
            for (int i = 0; i < 4; ++i) {numbers.push_back(randint(10));}
            bool correct = false;
            while (!correct) {
                // Start guess
                vector<int> numbers_buffer = numbers;
                cout << "Guess a 4-guess_digit number (e.g. 2345): ";
                string guess = "";
                cin >> guess;
                if (numbers.size() != guess.size()) {
                    error("Must enter a 4-guess_digit number");
                }
                int bulls = 0;
                int cows = 0;
                // Assess each guess_digit of guess (guess[i])
                for (int i = 0; i < numbers.size(); ++i) {
                    int guess_digit = guess[i] - '0';
                    int correct_digit = numbers[i];
                    if (guess_digit < 0 || guess_digit > 9) {
                        error("Must enter a 4-guess_digit number");
                    }
                    // Guessed digit correctly
                    if (guess_digit == correct_digit) {
                        ++bulls;
                        // Ensure digit in buffer is not counted towards cows
                        numbers_buffer[i] = -1;
                    }
                }
                if (bulls != numbers.size())
                {
                    for (int i = 0; i < numbers.size(); ++i) {
                        int guess_digit = guess[i] - '0';
                        int correct_digit = numbers[i];
                        // Guessed digit incorrectly
                        if (guess_digit != correct_digit) {
                            // Check against each number in numbers_buffer
                            for (int j = 0; j < numbers_buffer.size(); ++j) {
                                // If digit found in numbers_buffer
                                if (guess_digit == numbers_buffer[j]) {
                                    ++cows;
                                    numbers_buffer[j] = -1;
                                    break;
                                }
                            }
                        }
                    }
                }
                cout << endl << bulls << " bulls\n";
                cout << cows << " cows\n";
                if (bulls == numbers.size()) {
                    correct = true;
                }
            }
        }
    }
    catch (runtime_error e)
    {
        cout << e.what();
        return 1;
    }
}
