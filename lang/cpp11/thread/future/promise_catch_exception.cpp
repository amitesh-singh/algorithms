#include <iostream>
#include <chrono>
#include <thread>
#include <future>

void divCalc(std::promise<int> &p, int a, int b)
{
   try {
        if (b == 0) {
             throw std::runtime_error("div by zero");
        }
        p.set_value(a/b);
   } catch (...) {
        p.set_exception(std::current_exception());
   }
}

int main()
{
   std::promise<int> div;
   //The arguments to the thread function are moved or copied by value. If a reference argument needs to be passed to the thread function, it has to be wrapped (e.g. with std::ref or std::cref).
   //
   auto t = std::thread(divCalc, std::ref(div), 2, 0);

   //future
   auto f = div.get_future();
   try {
        std::cout << f.get() << '\n';
   } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
   }

   t.join();
   return 0;
}
