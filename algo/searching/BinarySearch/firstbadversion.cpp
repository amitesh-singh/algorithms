/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, 
the latest version of your product fails the quality check. Since each version
is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether version is bad.
Implement a function to find the first bad version. You should minimize the number of calls to 
the API.

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1
 
Constraints:

1 <= bad <= n <= 231 - 1
https://leetcode.com/problems/first-bad-version/

 int firstBadVersion(int n) {}
*/
#include <iostream>
#include <ctime>

int bad_num = 0;
void setBadNum(int n)
{
    bad_num = std::rand() % n + 1;

    std::cout << "bad num: " << bad_num << std::endl;
}

int isBadVersion(int x)
{
    if (x >= bad_num) return true;
    return false;
}

int fistBadVersion(int n)
{
    int low = 1, mid, high = n ;
    int ans = -1;
    while (low <= high)
    {
        mid = low + (high - low)/2;
        if (isBadVersion(mid) == true)
        {
            ans = mid;
            high = mid - 1;
            //go right side.
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    std::srand(std::time(nullptr));
    int n = 10;

    setBadNum(n);
    int res = fistBadVersion(n);
    std::cout << res << std::endl;
    if (fistBadVersion(n) == bad_num)
    {
        std::cout << "Pass\n";
    }
    else


    return 0;
}