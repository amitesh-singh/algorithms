/*
 * This question is asked by Microsoft. Given an array of strings, return the longest common prefix that is shared amongst all strings.
Note: you may assume all strings only contain lowercase alphabetical characters.

Ex: Given the following arrays...

["colorado", "color", "cold"], return "col"
["a", "b", "c"], return ""
["spot", "spotty", "spotted"], return "spot"
*/

#include <iostream>

using namespace std;

std::string getLCP(char *strList[], int strings_count)
{
   int index = 0;
   std::string ret;
   bool isDone = false;

   while (1)
     {
        for (int i = 1; i < strings_count; ++i)
          {
             if (strList[i - 1][index] == strList[i][index])
               continue;
             else
               {
                  isDone = true;
                  break;
               }
          }
        if (isDone)
          break;
        else
          {
            ret += strList[0][index];
            index++;
          }
     }
   return ret;
}

int main()
{
     {
        char *strList[] = {"colorado", "color", "cold"};
        int strings_count = 3;
        std::string lcp = getLCP(strList, strings_count);
        std::cout << lcp << std::endl;
     }
     {
        char *strList[] = {"a", "b", "c"};
        int strings_count = 3;
        std::string lcp = getLCP(strList, strings_count);
        std::cout << lcp << std::endl;
     }
     {
        char *strList[] = {"spot", "spotty", "spotted"};
        int strings_count = 3;
        std::string lcp = getLCP(strList, strings_count);
        std::cout << lcp << std::endl;
     }

   return 0;
}
