#include <iostream>

void towerofhanoi(char s, char d, char e, int n)
{
    if (n <= 0) return;
    towerofhanoi(s, e, d, n - 1);
    std::cout << "Move disk-" << n << " from " << s << " to " << e << std::endl;
    towerofhanoi(e, d, s, n - 1);
 }
int main()
{
    int n = 3;
    towerofhanoi('s', 'd', 'e', n);
    return 0;
}