#include <iostream>

class moving_average
{
   long sum = 0;
   unsigned int n = 0;
  public:
   double next(int val)
     {
        sum += val;
        n++;

        return double(sum)/n;
     }
};

int main()
{
   moving_average ma;

   for (int i = 1; i < 10; ++i)
     {
        std::cout << ma.next(i) << "->";
     }
   std::cout << std::endl;

   return 0;
}
