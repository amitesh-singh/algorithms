#include <iostream>
#include <cmath>
#include <vector>


bool isPrime(int n)
{
   if (n == 1 || n == 2) return true;

   for (int x = 2; x <= sqrt(n); ++x)
     {
        if (n % x == 0)
          return false;
     }

   return true;
}

//find all factors of a number
// eg. 9 = 1 * 3 * 3

std::vector<int> getFactors(int n)
{
   std::vector<int> factors;

   factors.push_back(1);
   while (n % 2 == 0)
     {
        factors.push_back(2);
        n = n/2;
     }

   //only odds are remaining
   //start with 3
   for (int x = 3; x <= sqrt(n); x += 2)
     {
        while (n % x == 0)
          {
             n = n/x;
             factors.push_back(x);
          }
     }
   std::cout << "n: " << n << std::endl;
   if (n > 2)
     factors.push_back(n);

   return factors;
}

int sumOddFactors(int n)
{
   int sum {0};

   if (n % 2 == 1) sum += n;
   //divide by 2 to make it odd
   while (n % 2 == 0)
     {
        n = n/2;
     }

   for (int x = 3; x < (n); x += 2)
     {
        if (n % x == 0)
          {
             sum += x;
          }
     }
   //add 1
   sum++;


   return sum;
}

int main()
{
   std::cout << "7: " << isPrime(7) << std::endl;
   std::cout << "123" << isPrime(123) << std::endl;
   for (int i = 1; i < 1001; ++i)
     {
        if (isPrime(i)) std::cout << i << " ";
     }
   std::cout << std::endl;

   std::vector<int> factors = getFactors(123);
   std::cout << "Factors: " << std::endl;
   for (auto &x: factors)
     std::cout << x << "x";

   factors.clear();

   factors = getFactors(1001);
   std::cout << "Factors: " << std::endl;
   for (auto &x: factors)
     std::cout << x << "x";

   std::cout << std::endl;

   std::cout << "sumof odd factors 18: " << sumOddFactors(9) << std::endl;
   return 0;
}
