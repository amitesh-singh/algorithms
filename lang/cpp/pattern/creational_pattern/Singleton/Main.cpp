#include<iostream>
#include "Singleton.cpp"
using namespace std;

int main()
{
    Singleton<int> *s = Singleton<int>::Instance();
    delete s;
    return 0;
}
