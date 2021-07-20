#include <iostream>

const static unsigned int SIZE = 1e5;
int input[SIZE];
int N = 0;
void heap_init()
{
    N = 0;
}

void heap_insert(int val)
{
    input[N++] = val;
    int i = N - 1;
    auto parent = [](int i) { return (i - 1) >> 1;};

    while (i != 0 and input[parent(i)] > input[i])
    {
        std::swap(input[parent(i)], input[i]);
        i = parent(i);
    }
}

void heap_print()
{
    for (int i = 0; i < N; ++i)
    {
        std::cout << input[i] << " ";
    }
    std::cout << '\n';
}

int main()
{
    //cout/cin are too slow. this makes cin/cout FAST.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    int n;
    int val;
    for (int t {0}; t < T; ++t)
    {
        heap_init();
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> val;
            heap_insert(val);
        }

        heap_print();
    }

    return 0;
}