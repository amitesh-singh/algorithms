#include <iostream>
#include <vector>

template<typename T>
class circular_array
{
   std::vector<T> v;
   int mSize;
  public:
   circular_array(int size):mSize(size)
     {
        v.reserve(size);
     }
   T& operator[](int i)
     {
        return v[i % mSize];
     }
   int size() const
     {
        return mSize;
     }
};

int main()
{
   circular_array<int> ca(10);
   ca[0] = 0;
   std::cout << ca[0] << std::endl;

   return 0;
}
