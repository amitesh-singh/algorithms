#include <array>
#include <iostream>
#include <algorithm>

void print(std::array<int, 6> &arr)
{
    for (auto &x: arr)
        std::cout << x << ", ";
    std::cout << std::endl;
}


void heapify(int arr[], int size, int i, bool downward = true)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest {0};
    if (l < size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    auto parent = [](int i) -> int {return (i-1)/2; };

    if (largest != i)
    {
        std::swap(arr[largest], arr[i]);
        if (downward)
            heapify(arr, size, largest);
        else
            heapify(arr, size, parent(i), false);
    }
}

int main()
{
    std::array<int, 6> arr{1, 2, 5, 9, 23, -1};
    
    std::make_heap(arr.begin(), arr.end());
    print(arr);
    int i = 4;
    arr[i] = 10;
    auto parent = [](int i) {return (i-1)/2; };
    if (arr.at(parent(i)) > arr[i])
    {
        heapify(arr.data(), arr.size(), i);
    }
    else
    {
        heapify(arr.data(), arr.size(), parent(i), false);
    }

    print(arr);

    return 0;
}