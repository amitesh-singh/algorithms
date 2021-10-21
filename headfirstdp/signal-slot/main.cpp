#include <iostream>
#include "signal.h"

int main()
{
   signal<std::string, int> sig;
   sig.connect([](std::string arg1, int arg2) {
               std::cout << arg1 << ":" << arg2 << "\n";
               });

   sig.emit("the answer is", 42);

   return 0;
}
