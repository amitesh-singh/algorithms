/*
 *
 * This question is asked by Facebook. Given a string and the ability to delete at most one character, return whether or not it can form a palindrome.
Note: a palindrome is a sequence of characters that reads the same forwards and backwards.

Ex: Given the following strings...

"abcba", return true
"foobof", return true (remove the first 'o', the second 'o', or 'b')
"abccab", return false
 * */

#include <iostream>

bool isPalindrom(const std::string &str, int index)
{
   unsigned int low = 0, high = str.size() - 1;
   while (low < high)
     {
        if (low == index) low++;
        if (high == index) high--;
        if (str[low] != str[high])
          return false;
        low++;
        high--;
     }

   return true;
}

bool isPartialPalindrome(const std::string &str)
{
   unsigned int low = 0, high = str.size() - 1;

   bool isPurePalindrom = true;
   while (low < high)
     {
        if (str[low] != str[high])
          {
             isPurePalindrom = false;
             //recheck if it's palindrom by deleting the str
             //check both, low and high?
             if (isPalindrom(str, low)) return true;
             if (isPalindrom(str, high)) return true;
          }
        low++;
        high--;
     }

   return isPurePalindrom;
}


int main()
{
   std::cout << isPartialPalindrome("abcba") << std::endl;
   std::cout << isPartialPalindrome("foobof") << std::endl;
   std::cout << isPartialPalindrome("abccab") << std::endl;
   return 0;
}
