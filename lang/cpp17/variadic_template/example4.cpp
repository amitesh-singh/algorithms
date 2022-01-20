#include <iostream>

#define F std::cout << __PRETTY_FUNCTION__ << std::endl
struct base
{
   template<class T>
   void get(T &&g)
     {
        F;
        std::cout << g << ",";
     }
   template<typename T, typename... Args>
    void get(T &&first, Args &&...args)
      {
         F;
         //std::cout << first << "<";
         get(first);
         get(args...);
      }
};


int main()
{

   base b;
   b.get(10);
   b.get(10, 20.0);
   return 0;
}

