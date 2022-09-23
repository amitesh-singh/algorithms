#include <iostream>


int main()
{
   auto g = new auto([]()->void {
                        std::cout << "lambda on heap\n";
                     });
   (*g)();
   delete g;

   return 0;
}
