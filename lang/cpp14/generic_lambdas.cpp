#include <iostream>

using namespace std;

int main()
{
  auto adder = [](auto a, auto b){ return a+b; };

  cout << adder(10, 11) << "\n";
  cout << adder(1.5, 2.5) << "\n";

  return 0;
}