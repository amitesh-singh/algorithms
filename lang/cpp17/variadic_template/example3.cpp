#include <iostream>

#define F std::cout << __PRETTY_FUNCTION__ << std::endl
template<class T>
void log(T obj)
{
   F;
   std::cout << obj << ",";
   std::cout << std::endl;
}

template<class T, typename... Args>
void log(T first, Args... args)
{
   std::cout << first << ",";
   std::cout << std::endl;
   log(args...);
}

int main()
{
   log('a', 1.24 , "Hello");
   log('a');
   log(std::string("a"), 1, 3.0f, 3.05);
   return 0;
}

