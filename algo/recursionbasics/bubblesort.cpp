#include <iostream>

void bubblesort(int *a, int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (a[j] > a[j + 1])
                std::swap(a[j], a[j+1]);
}

int main()
{
    int a[] = { 7, 8, -1, 0, 44, 5};
     for (auto &x: a)
        std::cout << x << " ";
    std::cout << '\n';

    bubblesort(a, sizeof(a)/sizeof(int));

    for (auto &x: a)
        std::cout << x << " ";
    std::cout << '\n';

    return 0;
}