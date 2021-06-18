//Given an integer array nums and an integer k, return true if there are two distinct
// indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
//https://leetcode.com/problems/contains-duplicate-ii/
//219. Contains Duplicate II


#include <iostream>
#include <vector>

#include <functional>
#include <chrono>

using namespace std;

//naive approach
// O(n^2)
bool containsNearbyDuplicate1(vector<int>& nums, int k)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        int j = i + 1;
        for (; j <= (k + i) && j < nums.size(); ++j)
        {
            if (nums[i] == nums[j])
                return true;
        }
    }

    return false;
}

// implement your optimize solution here.
bool containsNearbyDuplicate2(vector<int> &nums, int k)
{

}

struct TC
{
    std::string name;
    std::vector<int> v;
    int k;
    int expectedResult;
    
    TC(std::string name, std::vector<int> v, int k, bool result): name(name), v(v), k(k), expectedResult(result) {}

    void run(std::function<bool (std::vector<int> &, int)> f)
    {
        std::cout << name << "->";
        auto a = chrono::high_resolution_clock::now();
        bool res = f(v, k);
        auto b = chrono::high_resolution_clock::now();
        cout << "took " << chrono::duration_cast<chrono::microseconds>(b - a).count() << " microseconds; ";
        if (res == expectedResult)
        {
            std::cout << "passed\n";
        }     
    }
};

int main()
{
    //driver code
    {
        TC tc1("TC1", {1,2,3,1}, 3, true);
        tc1.run(containsNearbyDuplicate1);
    }
    
    {
        TC tc1("TC2", {1,0,1,1}, 1, true);
        tc1.run(containsNearbyDuplicate1);
    }
    {
        TC tc1("TC3", {1,2,3,1,2,3}, 2, false);
        tc1.run(containsNearbyDuplicate1);
    }

    return 0;
}