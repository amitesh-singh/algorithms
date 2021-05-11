#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    for (int i = 1; i < 10; ++i)
        v.push_back(i);
    
    std::random_shuffle(v.begin(), v.end());

    std::sort(begin(v), end(v));

    //now apply binary search
    auto isFound = std::binary_search(begin(v), end(v), 6);

    if (isFound)
        cout << "6 is present\n";
    else
        cout << "6 is absent\n";
    
    return 0;    
}