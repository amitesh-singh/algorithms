#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>

void printList(std::list<int> &l)
{
    for(auto i: l)
        std::cout << i << ", ";
    std::cout << std::endl;
}

int main()
{
    //allocate list upto 10 elements
    std::list<int> l(10);
    //fill list with -1
    std::fill(l.begin(), l.end(), -1);

    printList(l);

    l.push_back(100);
    l.push_front(10);

   printList(l);
    
    //sort list in ascending order.
    l.sort(); //without comparator function
    std::cout << "After sorting\n";
    printList(l);

    l.sort([](const int &a, const int &b)->bool {
        return a - b;
    });
    
    std::cout << "After sorting: descending order:- \n";
    printList(l);



    return 0;
}