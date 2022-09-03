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
   if (nums.size() == 0) return -1;
    int low = 0, mid, high = nums.size();
    int ans = -1;
    while (low < high)
    {
        mid = low + (high - low)/2;

        if (nums[mid] == false)
        {
            ans = mid;
            high = mid;
        }
        else
            low = mid + 1;
    }

    return ans;
}

void print_tc(vector<bool> const & v)
{
   for (const auto &x: v)
     std::cout << x << " ";
   std::cout << '\n';
}

vector<bool> make_tc(int ones, int zeroes)
{
   vector<bool> v;
   for (auto i = 0; i < ones; ++i)
     v.push_back(true);
   for (auto i = 0; i < zeroes; ++i)
     v.push_back(false);

   return v;
}


int main()
{
    vector<bool> v =  {true, true, true, true, true,
                false, false, false, false, false, false};
    print_tc(v);
    std::cout << findFirstFalse(v) << std::endl;
    v.clear();

    v = make_tc(3, 5);
    print_tc(v);

    std::cout << findFirstFalse(v) << std::endl;

    v = make_tc(3, 0);
    print_tc(v);
    std::cout << findFirstFalse(v) << std::endl;

    v = make_tc(0, 3);
    print_tc(v);

    std::cout << findFirstFalse(v) << std::endl;

    return 0;
}
