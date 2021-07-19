#include <iostream>
#include <algorithm>

const int SIZE = 1e6 + 5;
int input[SIZE];
int output[SIZE];

unsigned int getSwaps(int *A, int n)
{
    unsigned int ans = 0;
    //find no. of inversions
    int j;
    for (int i = 0; i < n; ++i)
    {
        j = i + 1;
        while (j < n)
        {
            if (A[i] > A[j])
                ans++;
        }
    }

    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, n;
    std::cin >> T;
    for (int i = 0; i < T; ++i)
    {   
        std::cin >> n;
        for (int j = 0; j < n; ++j)
        {
            std::cin >> input[j];
        }

        std::cout << getSwaps(input, n) << '\n';
    }
    return 0;
}