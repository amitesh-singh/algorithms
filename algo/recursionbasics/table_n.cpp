#include <iostream>

//below code print the mathematical table of n

void printTable(int n, int i)
{
    if (i <= 0) return;
    printTable(n, i - 1);
    printf("%d * %d = %d\n", n, i, n * i);
}

int main()
{
    printTable(3, 10);
    return 0;
}