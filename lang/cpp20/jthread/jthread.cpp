#include <thread>
#include <iostream>


int main()
{
   //joins automatically
   std::jthread jth {[] {std::cout << "joinable std::jthread" << "\n";}};
   std::cout << "jth.joinable=" << jth.joinable() << "\n";

   return 0;
}
