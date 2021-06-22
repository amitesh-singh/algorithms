#include <iostream>
#include <vector>
#include <algorithm>

/*
Given an array of integers sorted in ascending order,
find the frequency of given value.
Solve it in O(log n)
*/

int getFreq(std::vector<int> &nums, int key)
{
    //find the lower and upper bound and get a difference. do check if key exists or not.
    auto l = std::lower_bound(std::begin(nums), std::end(nums), key);
    auto r = std::upper_bound(std::begin(nums), std::end(nums), key);
    if (*l != key) return 0;

    return r - l;
}

int main()
{
    std::vector<int> v1 = {1, 2, 4, 4, 4, 5, 6};
    //using stl

    int key = 4;
  
    std::cout << getFreq(v1, key) << std::endl;
    
    key = 1;
    std::cout << getFreq(v1, key) << std::endl;
    key = -1;
    std::cout << getFreq(v1, key) << std::endl;
    return 0;
}