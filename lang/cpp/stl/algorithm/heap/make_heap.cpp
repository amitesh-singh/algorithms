#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> v{10, 20, 30, 14};
    std::make_heap(v.begin(), v.end());

    std::cout << "initial max heap: " << v.front() << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::make_heap(v.begin(), v.end(), std::greater<int>{});
    std::cout << "initial min heap: " << v.front() << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    //make it max heap again
    std::make_heap(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    //add one element
    std::cout << "pushing 40\n";
    v.push_back(40);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::cout << "Applying push_heap()\n";
    //call push_heap() to heapify the items.
    std::push_heap(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    ///pop_heap to delete the max element.
    // extract-heap-max
    std::cout << "extract max heap\n";
    std::pop_heap(v.begin(), v.end());
    std::cout << "max element now is : " << v.front() << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    //sort_heap
    // sort the heap, aftert this operation, container is no longer a heap.
    std::cout << "applying sort_heap()\n";
    std::sort_heap(v.begin(), v.end());
    for (int &x: v)
      std::cout << x << ", ";
    std::cout << std::endl;

    //check if container is heap or not
    is_heap(v.begin(), v.end())? std::cout << "it's a heap\n" : std::cout << "it's not a heap\n";

    std::make_heap(v.begin(), v.begin() + 2);
    auto it = is_heap_until(v.begin(), v.end());
    for (auto it1 = v.begin(); it != it1; ++it1)
      {
         std::cout << *it1 << ", ";
      }
    std::cout << std::endl;

    return 0;
}
