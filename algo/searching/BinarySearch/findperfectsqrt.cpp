#include <iostream>

//find if a number is perfect square without using sqrt

bool isPerfectSquare(int n)
{
    if (n == 0 || n == 1) return true;

    //2 to n - 1
    int low = 2, high = n - 1;
    unsigned long mid;
    while (low <= high)
    {
        mid = low + (high - low)/2;
        //std::cout << "mid: " << mid << std::endl;
        if (mid*mid == n)
            return true;
        else if (mid * mid > n)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return false;
}
int main()
{
    bool res = isPerfectSquare(16);
    std::cout << "isPerfectSquare(16): " << res << std::endl;
    std::cout << "isPerfectSquare(199991): " << isPerfectSquare(199991) << std::endl;

    for (int i = 0; i < 100000; ++i)
    {
        if (isPerfectSquare(i))
        {
            std::cout << i << ": " << "perfect square.\n";
        }
    }

    return 0;
}