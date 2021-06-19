/*
 * Given a string, return whether or not it forms a palindrome ignoring case and non-alphabetical characters.
Note: a palindrome is a sequence of characters that reads the same forwards and backwards.

Ex: Given the following strings...

"level", return true
"algorithm", return false
"A man, a plan, a canal: Panama.", return true
*/

#include <iostream>
#include <cstring>

bool isPalindrome(const std::string &str)
{
   if (str == "") return false;

   unsigned int low = 0;
   unsigned int high = str.size() - 1;

   while (low < high)
     {
        while (!isalpha(int(str[low])))
          low++;
        while (!isalpha(int(str[high])))
          high--;
        if (tolower(str[low++]) != tolower(str[high--]))
            return false;
     }

     return true;
}

int main()
{
   std::cout << isPalindrome("level") << std::endl;
   std::cout << isPalindrome("algorithm") << std::endl;
   std::cout << isPalindrome("A man, a plan, a canal: Panama.") << std::endl;
   std::cout << "isalpha(' '): " << isalpha(' ') << std::endl;
   return 0;
}
