#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>

std::binary_semaphore mainToOdd {0}, oddToEven{0}, evenToOdd {0};

void printOdd(std::vector<int> &v, int &index)
{
    mainToOdd.acquire();
    while (1)
    {
        evenToOdd.acquire();
        std::cout << v[index++] << " ";
        oddToEven.release();
        if (index >= 200) break;
    }
}

void printEven(std::vector<int> &v, int &index)
{
    while (1)
    {
        oddToEven.acquire();
        std::cout << v[index++] << " ";
        evenToOdd.release();
        if (index >= 200) break;
    }
}

int main()
{
    std::vector<int> v;
    for (int i = 1; i <= 200; ++i)
        v.push_back(i);

    int index {0};
    std::thread oddT(printOdd, std::ref(v), std::ref(index));
    std::thread evenT(printEven, std::ref(v), std::ref(index));

    mainToOdd.release();
    evenToOdd.release();

    oddT.join();
    evenT.join();

    return 0;
}
