#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> v(10);
    //gives the distance between same type of iterators
    cout << std::distance(v.begin(),v.end());

    return 0;
}
