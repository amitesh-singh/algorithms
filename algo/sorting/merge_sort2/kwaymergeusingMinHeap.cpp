#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;



template<class T>
class Heap
{
    vector<vector<T> > &m_children;
    public:
    Heap(vector< vector<T> > &vec)
    {

    }
};
int main()
{
    vector<int> vec1;
    vector<int> vec2;
    vec1.push_back(10);
    vec1.push_back(13);
    vec1.push_back(16);
    vec2.push_back(1);
    vec2.push_back(11);
    vec2.push_back(15);

    vector<vector<int> > vec;
    vec.push_back(vec1);
    vec.push_back(vec2);

    Heap<int> heap(vec);

    return 0;
}
