#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <forward_list>

void printList(std::list<int>& l)
{
    for (auto i : l)
        std::cout << i << ", ";
    std::cout << std::endl;
}

int main()
{
    //single linked list
    std::forward_list<int> l2;

    //doubly linked list
    //allocate list upto 10 elements
    std::list<int> l(10);
    //fill list with -1
    std::fill(l.begin(), l.end(), -1);

    printList(l);
    //change all values
    int j = 0;
    //this is how you set the values 
    // for (auto i: l) won't work 
    for (auto& i : l)
    {
        i = j++;
    }
    //insert at tail
    l.push_back(100);
    //insert at head
    l.push_front(10);

    printList(l);

    l.pop_back(); //delete at back
    l.pop_front(); //delete at head. //remove head.
    l.erase(l.begin()); //this also deletes at front


    //sort list in ascending order.
    l.sort(); //without comparator function
    std::cout << "After sorting\n";
    printList(l);

    //with a comparator lambda function
    l.sort([](const int& a, const int& b)->bool {
        return a > b;
        });

    std::cout << "After sorting: descending order:- \n";
    printList(l);


    std::list<int> list2;
    int index = 2;
    l.splice(l.begin(), list2);
    std::cout << "printing list2: \n";
    printList(list2);

    l.push_back(7);
    printList(l);

    /// remove an element by value
    std::cout << "removing an element by value 7\n";
    //removes multiple value with 7
    l.remove(7);

    printList(l);
    std::cout << "removing all even values using remove_if: \n";
    //delete odd values only
    l.remove_if([](const int& val)->bool { return val % 2 == 0 ? true : false; });
    
    printList(l);

    l.push_front(1);

    printList(l);

    l.sort();
    list2.sort();
  
    //merge two sorted arrays
    l.merge(list2);

    printList(l);
    std::cout << "printing list2:\n";
    printList(list2);

    l.clear();

    return 0;
}
