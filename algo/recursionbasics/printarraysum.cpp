#include<iostream>
#include <vector>
/*
Given an array, arr, of integers, write a recursive function that add sum
of all previous numbers to each index of array.
e.g.
1, 2, 3, 4, 5, 6
-> 1, 3, 6, 10, 15, 21

*/
int sum(int a[], int n)
{
    if (n == 0) return a[0];
    a[n] = sum(a, n-1) + a[n];
    return a[n];
}

int  main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    std::cout << "input: ";
    for (auto &x: a)
       std::cout << x << " ";
    std::cout << std::endl;
    sum(a, sizeof(a)/sizeof(int));
    std::cout << "output: ";
    for (auto &x: a)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}