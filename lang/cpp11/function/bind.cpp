#include <functional>
#include <iostream>

void mycallback(std::function<void(int)> f)
{
   f(10);
}

void cb(int, const char *str)
{
   std::cout << str << std::endl;
}

namespace my_placeholders
{
   auto id = std::placeholders::_1;
}

void cb2(int, int &i)
{
   i++;
   std::cout << i << std::endl;
}

void cb3(int, int *i)
{
   ++(*i);
   std::cout << *i << std::endl;
}

int main()
{
   mycallback(std::bind(cb, std::placeholders::_1, "hey man"));

   int i = 0;
   //for passing reference, do std::ref()
   mycallback(std::bind(cb2, my_placeholders::id, std::ref(i)));
   mycallback(std::bind(cb2, my_placeholders::id, std::ref(i)));

   //or pass pointer
   mycallback(std::bind(cb3, my_placeholders::id, &i));
   return 0;
}
