#include<set>
#include <iostream>

template<typename T>
struct minheap
{
    std::multiset<T> heap;

    T top()
    {
        if (!heap.empty()) {
            return *heap.begin();
        }
    }

    void pop()
    {
        if (heap.empty()) {
            return;
        }

        heap.erase(heap.begin());
    }

    void insert(T&& val)
    {
        heap.insert(std::forward<T>(val));
    }
    
    //in interviews, show this awesome skills man!!
    void insert(auto&&... val)
    {
        (heap.insert(val), ...);
    }

};

int main()
{
    minheap<int> mheap;
    mheap.insert(10);
    mheap.insert(1);

    std::cout << "top: " << mheap.top() << '\n';

    mheap.pop();

    std::cout << "top: " << mheap.top() << '\n';

    mheap.insert(20, 12, 12, 0, 1);
    
    std::cout << "top: " << mheap.top() << '\n';

    return 0;
}