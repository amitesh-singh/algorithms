#include <iostream>

enum class Options {None, One, All};

int main()
{
  Options o = Options::None;

  if (o == Options::None)
    std::cout << "Option is None\n";

  return 0;
}