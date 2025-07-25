// Created by Orlando Shamlou on 2025/07/25
// Following PPP3 §19_2

// Copy elements of an array of ints into another using iterators (not subscripting)

/* Iterator operations to use
 * p==q
 * p!=q
 * *p
 * *p=val
 * val=*p
 * ++p
 */

void copy(int* f1, int* e1, int* f2);

#include <iostream>

int main()
{
    int a[] {10, 20, -1};
    int b[] {0, 0, 0};
    copy(a,a+(sizeof(a) / sizeof(a[0])),b);
    std::cout << b[0] << " " << b[1] << " " << b[2] << "\n";
}

// Input array: [f1:e1)
// Output array: [f2:f2+(e1-f1)]
void copy(int* f1, int* e1, int* f2)
{
    int* max = f2+(e1-f1);
    while (f2 < max)
    {
        *f2=*f1;
        ++f1;
        ++f2;
    }
}