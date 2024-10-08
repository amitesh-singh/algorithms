#include <iostream>

#include <cstring> // for strcmp

static unsigned long long seed = 1;

void _srand(unsigned long long s)
{
   seed = s;
}

unsigned long long _rand()
{
   seed = 42331*seed + 123457;
   return seed/101;
}

using namespace std;

template<class T>
bool comp(T &l, T &r)
{
    return l < r;
}

template<class T>
bool comp2(T l, T r)
{
    return strcmp(l, r) < 0;
}

template<class T>
void _swap(T &l, T &r)
{
    T temp = l;
    l = r;
    r = temp;
}

template<typename T, typename F>
int partition(T a[], int low, int high, F f)
{
    int index, i, pivot;

    index = low;
    pivot = high;

    for (i = low; i < high; ++i)
    {
        if (f(a[i], a[pivot]))
        {
            _swap(a[i], a[index]);
            index++;
        }
    }
    _swap(a[pivot], a[index]);

    return index;
}

template<typename T, typename F>
int randomPartition(T a[], int low, int high, F f)
{
    //int pivot = low + rand() % (high - low + 1);
    int pivot = low + _rand() % (high - low + 1);

    _swap(a[high], a[pivot]);

    return partition(a, low, high, f);
}

template <typename T, typename F>
void Qsort(T a[], int low, int high, F f)
{
    int pivot;
    if (low < high)
    {
        pivot = randomPartition(a, low, high, f);
        Qsort(a, low, pivot - 1, f);
        Qsort(a, pivot + 1, high, f);
    }
}

int main()
{
    int A[] = {1, 0, 9, 2329, -98, 32, 0, 1, 34, 100, 1000, 1002, 32, 324, 34324, 2312, 23443, 323423, 2324311, 234345, 34534, 435345, 2334543, 32423421, -923, 23432, 3321423, 234231, 44, 43435, 2324354,
    23423, 4334545, 4322, 3445, 345545, 3421367, 678798,9999, 78854343, 24354};

    _srand(1001);
    Qsort<int>(A, 0, sizeof(A)/sizeof(int) - 1, comp<int>);

    for (int i = 0; i < sizeof(A)/sizeof(int); ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    char *s[] = {"banana", "anana", "nana", "ana", "na", "n"};

    _srand(1001);

    Qsort<char *>(s, 0, 6 - 1, comp2<char *>);
    for (register int i = 0; i < 6; ++i)
    {
        cout << s[i] << " ";
    }
    cout << "\n";

    return 0;
}
