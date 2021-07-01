/**
 *
 *
 * check if following brackets is valid
 * a()()) (a)(54)()()
 */
#include <iostream>
#include <string>
#include <stack>

//this only works if you got () one pair of brackets
// it won't work for {}() {()[]}
// check leetcode problem on this.
bool isValid(const std::string &input)
{
    int n = input.size();
    if (n == 0) return true;
    int cnt {0};

    for (auto &x: input)
      {
         if (x == '(') cnt++;
         else if (x == ')') cnt--;
         //check for )(
         if (cnt < 0) return false;
      }

    return cnt == 0;
}

//using stack
//
bool isValid2(const std::string &input)
{
   if (input.size() == 0)  return true;
   std::stack<char> s;

   for (auto &x: input)
     {
        if (x == '(') s.push(x);
        else if (x == ')')
          {
             if (!s.empty())
               {
                  if (s.top() == '(')
                    s.pop();
               }
             else
               {
                  return false;
               }
          }
     }

   return s.empty() == true;
}

int main()
{
   std::cout << isValid("a()())") << std::endl;
   std::cout << isValid("a()(5)") << std::endl;
   std::cout << isValid(")a()(5)") << std::endl;

   std::cout << isValid2("a()())") << std::endl;
   std::cout << isValid2("a()(5)") << std::endl;
   std::cout << isValid2(")a()(5)") << std::endl;

   return 0;
}
