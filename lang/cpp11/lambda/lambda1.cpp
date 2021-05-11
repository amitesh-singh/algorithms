#include <iostream>
#include <vector>

using namespace std;

using funcptr = void (*)();
void callback(funcptr f)
{
   f();
}

int main()
{
   int result = [](int input)->int { return input * input; }(10);
   cout << result << endl;

   // in case, you want to reuse the lambda function
   auto func = [](int input) { return  input * input; };
   // in case of cpp14, you could make argument auto. This is not allowed in
   // cpp11

  //auto func = [](auto intput) { return input * input; } --> allowed in cpp14, but not in cpp11.

   cout << func (100) << endl;

   //pass lambda function as argument
   callback([]()->void{cout << "Hey! what's up!\n";});

   std::vector<int> v = {1, 2, 3, 4};
   

   return 0;
}

