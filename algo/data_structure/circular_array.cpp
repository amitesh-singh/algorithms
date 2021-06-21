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
        for (int i = 0; i < size; ++i)
            v.push_back(0);
     }

   circular_array(const std::initializer_list<T> &rhs)
     {
        v.reserve(rhs.size());
        mSize = rhs.size();
        for (auto &x: rhs)
          {
             v.push_back(x);
          }
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
   std::cout << ca[12] << std::endl;

   circular_array<int> arr2  {1, 2, 3, 4, 5};
   std::cout << arr2[12] << std::endl;
   std::cout << "size: " << arr2.size() << std::endl;

   return 0;
}
