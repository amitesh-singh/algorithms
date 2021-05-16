#include <iostream>
#include <thread>
#include <future>
#include <vector>

void f(std::vector<int>)
{
}

void f(int)
{
}

int main()
{
   //auto task = std::async(std::launch::asycn, f, 10); //it won't compile..
   // two ways to solve this
   // 1. typecast the function
   // std::async(..., (void (*)(int))f, 10);
   // 2. use fptr
   // using fptr = void (*)(int);
   // fptr fp = f;
   // std::async(.., fp, 10);
   auto task = std::async(std::launch::async, static_cast<void (*)(int)>(f), 10);

   task.get();

   return 0;
}
