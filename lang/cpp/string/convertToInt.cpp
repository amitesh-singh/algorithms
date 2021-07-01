//"123" to 123
//"-45" to -45
#include <iostream>

void handleException() try
{
   throw;
}
catch (std::exception &e)
{
   std::cout << e.what() << std::endl;
}

int convertToInt(const std::string &str)
{
   int ans = 0;
   bool isnegative = false;
   try
     {
        if (str == "") throw std::logic_error("invalid input");

        int n = str.size() - 1;
        int cnt = 0;
        if (str[0] == '-') isnegative = true, cnt++;
        while (cnt <= n)
          {
             char c = str[cnt];

             if (!std::isdigit(c)) throw std::logic_error("one of char is not digit");
             ans = ans * 10 + (c - '0');
             cnt++;
          }
     }
   catch (...)
     {
        handleException();
     }

   ans = isnegative ? -1 * ans : ans;
   return ans;
}

int main()
{
   std::cout << convertToInt("456") << std::endl;
   std::cout << convertToInt("-45") << std::endl;
   std::cout << convertToInt("-4&45") << std::endl;

   std::cout << std::stoi("-4&45") << std::endl;
   return 0;
}
