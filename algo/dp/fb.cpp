#include <iostream>
#include <unordered_map>
using namespace std;
//using top down approach

int fib_topdown(int i, unordered_map<int, int> &hash)
{
   if (i == 0 or i == 1) return i;

   if (hash.find(i) == hash.end())
     hash[i] = fib_topdown(i - 1, hash) + fib_topdown(i - 2, hash);

   return hash[i];
}

int main()
{
   std::unordered_map<int, int> hash;
   cout << "fib(2): " << fib_topdown(2, hash) << endl;
   cout << "fib(5): " << fib_topdown(5, hash) << endl;
   cout << "fib(10): " << fib_topdown(10, hash) << endl;

   return 0;
}
