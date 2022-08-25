#include <iostream>
#include <vector>


/*
 * for (auto a: {1, 2, 3}) -->
 *  for (a = begin(container); a != end(container); ++a)
 * so we need begin() and end() to be implemented in the custom class
 * */

class str
{
   char *p_;
   int n;

  public:
   str(const char *p) {
        if (p == nullptr) {
             p_ = nullptr;
             n = 0;
             return;
        }
        n = strlen(p) + 1;
        p = new char[n];
   }
   ~str()
     {
        delete [] p_;
     }
   char operator[](const int i) {
        if (i > n) {
             //throw error
        }
        return p_[i];
   }
   
};
int main()
{
   for (int i : {1, 2, 4})
     std::cout << i << '\n';

   std::vector<int> v = {4, 6, 7};
   for (const auto &i : v )
     std::cout << i << '\n';

   return 0;
}
