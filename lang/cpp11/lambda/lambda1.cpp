#include <iostream>

using namespace std;

int main()
{
   int result = [](int input) { return input * input; }(10);
   cout << result << endl;

   // in case, you want to reuse the lambda function
   auto func = [](int input) { return  input * input; };
   // in case of cpp14, you could make argument auto. This is not allowed in
   // cpp11

  //auto func = [](auto intput) { return input * input; } --> allowed in cpp14, but not in cpp11.

   cout << func (100) << endl;

   return 0;
}

