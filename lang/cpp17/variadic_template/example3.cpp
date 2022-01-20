#include <iostream>

template<class T>
void log(T obj)
{
   std::cout << obj << ",";
}

template<class T, typename... Args>
void log(T first, Args... args)
{
   std::cout << first << ",";
   log(args...);
}

int main()
{
   log('a', 1.24 , "Hello");
   log('a');
   return 0;
}

