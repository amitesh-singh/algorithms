/*
 *A child is running up a staircase with n steps and can hop either 1 step,
 2 steps, or 3 steps at a time. Implement a method to count how many possible
 ways the child can run up the stairs.
 */
//TODO implement it with BigInteger class
#include <iostream>
#include <unordered_map>

unsigned long steps_count(int i, std::unordered_map<int, unsigned long> &hash)
{
   if (i < 0) return 0;
   else if (i == 0) return 1;

   if (hash.find(i) == hash.end())
     hash[i] = steps_count(i - 1, hash) + steps_count(i - 2, hash) + steps_count(i - 3, hash);

   return hash[i];
}

int main()
{
   std::unordered_map<int, unsigned long> hash;
   std::cout << steps_count(370, hash) << std::endl;
   std::cout << steps_count(4, hash) << std::endl;
   //TODO: handle overflow
   return 0;
}
