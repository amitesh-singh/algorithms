/*
 *
 * This question is asked by Amazon. Given a string representing the sequence of moves a robot vacuum makes, return whether or not it will return to its original position. The string will only contain L, R, U, and D characters, representing left, right, up, and down respectively.

Ex: Given the following strings...

"LR", return true
"URURD", return false
"RUULLDRD", return true
 * */

#include <iostream>
#include <string>

struct pos
{
   int x = 0, y = 0;
};
bool isBackToHome(const std::string &s)
{
   if (s.size() == 0) return false;

   int n = s.size() - 1;

   pos start;

   while (n >= 0)
     {
        switch(s[n--])
          {
            case 'L':
                start.x -= 1;
                break;
            case 'R':
                start.x += 1;
                break;
            case 'U':
                start.y += 1;
                break;
            case 'D':
                start.y -= 1;
                break;
          }
     }

   if (start.x == 0 && start.y == 0)
     return true;
   else
     return false;
}

int main()
{
   std::cout << isBackToHome("LR") << std::endl;
   std::cout << isBackToHome("URURD") << std::endl;
   std::cout << isBackToHome("RUULLDRD") << std::endl;
   return 0;
}

