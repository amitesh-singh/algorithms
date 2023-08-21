#include <iostream>
#include <source_location>

void log(const char *msg, const std::source_location &loc = std::source_location::current())
{
  std::cout << loc.file_name() << ": " << loc.line() << ": " << loc.function_name() << ":" << loc.column();
  std::cout << ": " << msg << '\n';
}

void func()
{
  log("inside func");
}

int main()
{
  log("Hello from main");
  return 0;
}
