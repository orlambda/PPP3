#include <iostream>
using std::cin, std::cout, std::string, std::endl;
#include <vector>
using std::vector;

// Find all prime numbers between 1 and 100 (first prime is 2) using the Sieve of Eratosthenes

bool is_composite(const vector<int>& values, int x);
void mark_prime(vector<int>& values, int x);
void mark_composite(vector<int>& values, int x);
void print_primes(const vector<int>& values);

int main() {
    // QUESTION - reading input into a const
    // Store input in temporary variable then assign?
    // or get_int()-style function?
    cout << "Listing all primes from 1 to a given integer inclusive." << endl << "Max value: ";
    int temp_max;
    cin >> temp_max;
    const int max = temp_max;
    cout << "Primes:" << endl;
    // Make vector
    // Default value is 0
    // 1 means prime, 0 means unknown, -1 means composite
    vector<int> values(max + 1);
    // 0 and 1 are not primes
    values[0] = -1;
    values[1] = -1;
    // Loop through all numbers from min to max inclusive
    for (int i = 0; i <= max; ++i) {
        if (!is_composite(values, i) == 1) {
            mark_prime(values, i);
        }
    }
    print_primes(values);
}

bool is_composite(const vector<int>& values, int x)
{
    // If has not been marked as composite
    // alternatively, if values[x] == 0
    if (values[x] == -1)
    {
        return true;
    }
    return false;
}

void mark_prime(vector<int>& values, int x)
{
    values[x] = 1;
    // Mark composites
    for (int i = 2 * x; i < values.size(); i += x)
    {
        mark_composite(values, i);
    }
}

void mark_composite(vector<int>& values, int x)
{
    values[x] = -1;
}

void print_primes(const vector<int>& values)
{
    for (int i = 0; i < values.size(); ++i)
    {
        if (values[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}