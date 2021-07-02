#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

int main()
{
   std::srand(std::time(nullptr));
    vector<int> v(10);
    
    std::generate(v.begin(), v.end(), rand);

    for(auto &x: v)
        cout << x << ", ";
    cout << endl;
    std::sort(begin(v), end(v));
    
    return 0;
}
