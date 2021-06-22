/*
 I have an array with boolean values. But sequence of elements like these: 
 first go true values, and then false values. For example,

boolean[] booleans = {true, true, true, true, true,
                false, false, false, false, false, false};

The task is to find first false element.
***/
#include <iostream>
#include <vector>

using namespace std;

int findFirstFalse(vector<bool> &nums)
{
    int low = 0, mid, high = nums.size();
    int ans = -1;
    while (low <= high)
    {
        mid = low + (high - low)/2;

        if (nums[mid] == false)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}


int main()
{
    vector<bool> v =  {true, true, true, true, true,
                false, false, false, false, false, false};
    std::cout << findFirstFalse(v) << std::endl;


    return 0;
}