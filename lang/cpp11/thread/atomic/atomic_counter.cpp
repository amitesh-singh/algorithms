#include <atomic>
#include <thread>
#include <iostream>

struct atomic_counter
{
   std::atomic<int> val = 0;
   void increment()
     {
        ++val;
     }

   void decrement()
     {
        --val;
     }

   int get() const
     {
        return val;
     }
   void print()
     {
        std::cout << val << std::endl;
     }
};

int main()
{
   atomic_counter c;
   //incrementer
   std::thread t1([](atomic_counter &counter)->void
                  {
                  while (1)
                  {
                    counter.increment();
                    std::cout << "+: ";
                    counter.print();
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                  }
                  }, std::ref(c));

   //decrementer
   std::thread t2([](atomic_counter &counter)->void
                  {
                  while (1)
                  {
                    counter.decrement();
                    std::cout << "-:";
                    counter.print();
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                  }
                  }, std::ref(c));

   t1.join();
   t2.join();

   return 0;
}
