/*
 * This question is asked by Apple. Given two binary strings (strings containing only 1s and 0s) return their sum (also as a binary string).
Note: neither binary string will contain leading 0s unless the string itself is 0

Ex: Given the following binary strings...

"100" + "1", return "101"
"11" + "1", return "100"
"1" + "0", return  "1"
 * */

#include <iostream>

std::string addBinary(const std::string &s1, const std::string &s2)
{
   int n1 = s1.size() - 1;
   int n2 = s2.size() - 1;

   std::string res(std::max(n1 + 1, n2 + 1) + 1, '0');

   int sum = 0, carry = 0;
   int x1, x2;
   int index = res.size() - 1;
   while (n1 >= 0 || n2 >= 0)
     {
        x1 = n1 >= 0 ? s1[n1] - '0': 0;
        x2 = n2 >= 0 ? s2[n2] - '0' : 0;

        sum = x1 + x2 + carry;
        carry = sum/2;
        sum = sum % 2;
        res[index--] = sum == 0 ? '0' : '1';
        n1--;
        n2--;
     }
   if (carry == 1)
     res[index] = '1';

   return res;
}

int main()
{
   std::cout << addBinary("100", "1") << std::endl;
   std::cout << addBinary("1", "1") << std::endl;
   std::cout << addBinary("11", "1") << std::endl;

   return 0;
}
