#include <thread>
#include <atomic>
#include <iostream>

enum class state
{
   working,
   not_working
};

std::atomic<state> mystate(state::not_working);

int main()
{
   std::thread t([]() {
                    mystate.store(state::working);
                 });

   t.join();

   std::cout << static_cast<int>(mystate.load()) <<  std::endl;
   return 0;
}
