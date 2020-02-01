/*
 *
 *Variable Templates

C++14 allows variables to be templated:

template<class T>
constexpr T pi = T(3.1415926535897932385);
template<class T>
constexpr T e  = T(2.7182818284590452353);
*/

#include <iostream>
using namespace std;

template<class T>
constexpr T pi = T(3.1459);

int main()
{
   cout << pi<int> << endl;
   cout << pi<double> << endl;

   return 0;
}
