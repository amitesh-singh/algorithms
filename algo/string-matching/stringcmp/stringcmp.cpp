#include <iostream>

using namespace std;

void mstrcpy(char dest[], char src[])
{
    unsigned char *p1 = (unsigned char *)dest;
    unsigned char *p2 = (unsigned char *)src;
    while (*p1++ = *p2++);
}

int mstrcmp(char *str1, char *str2)
{
    const unsigned char *p1 = (const unsigned char *)str1;
    const unsigned char *p2 = (const unsigned char *)str2;

    while (*p1 && (*p1 == *p2)) p1++, p2++;

    return (*p1 > *p2) - (*p2 > *p1);
}

int main()
{
    char dest[100];
    char *src = "OkGoogling ok";
    
    mstrcpy(dest, src);
    cout << dest << endl;
    cout << mstrcmp(dest, src) << endl;

    return 0;
}