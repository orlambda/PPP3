// Created by Orlando Shamlou on 2025/07/25
// Following PPP3 §19.2.1

// This needs someone to look over it

// Exercise: this has an error.
// Find it, fix it, and suggest a general remedy for that kind of problem.
// My solution: wrap the array in a class that deletes it in its destructor

#include <iostream>
#include <iterator>

template<class T>
struct Safe_array
{
    T data;
    Safe_array(const T& d) : data{d}{}
    ~Safe_array()
    {
        delete data;
    }
};

// Return an iterator to the element in [first:last) that has the highest value
template<std::forward_iterator Iter>
Iter high(Iter first, Iter last)
{
    Iter high = first;
    for (Iter p = first; p!=last; ++p)
        if (*high<*p)
            high = p;
    return high;
}

// Fill an array, put number of elements in *count
double* get_from_jack(int* count)
{
    // Some test data
    return new double[]{100, -20, 3.5};
}


// Fill a vector
std::vector<double> get_from_jill()
{
    // Some test data
    std::vector<double> v {-100, 1000.5, 20, 0};
    return v;
}

int main()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    Safe_array jack_safe_data{jack_data};
    std::vector<double> jill_data = get_from_jill();
    double* jack_high = high(jack_safe_data.data,jack_safe_data.data + jack_count);
    double* jill_high = &(*(high(jill_data.begin(), jill_data.end()))); // ew?
    std::cout << "Jack high: " << *jack_high << ", Jill high: " << *jill_high << std::endl;
}