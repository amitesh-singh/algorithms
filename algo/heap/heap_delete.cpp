#include <array>
#include <iostream>
#include <algorithm>

void print(std::array<int, 6> &arr, int size = 6)
{
   for (int i = 0; i < size; ++i)
     std::cout << arr[i] << ", ";
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
    std::cout << "deleting " << arr[i];

    arr[i] = 10;
    std::cout << " by " << arr[i] << std::endl;

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

    //deleting 1 
    
    i = 1;
    std::cout << "deleting " << arr[i];
    std::cout << std::endl;
    arr[i] = arr[arr.size() - 1];

    if (arr.at(parent(i)) > arr[i])
      heapify(arr.data(), arr.size() - 1, i);
    else
      heapify(arr.data(), arr.size() - 1, parent(i), false);

    print(arr, arr.size() - 1);

    return 0;
}
