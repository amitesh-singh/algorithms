#include <iostream>

using namespace std;

int main()
{
   int result = [](int input) { return input * input; }(10);
   cout << result << endl;

   // in case, you want to reuse the lambda function
   auto func = [](int input) { return  input * input; };

   cout << func (100) << endl;

   return 0;
}

