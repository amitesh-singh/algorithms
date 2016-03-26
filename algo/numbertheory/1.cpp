#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
void product(string a, string b)
{
   vector<int> result(a.size() + b.size(), 0);
   for( int i = a.size() - 1; i >= 0; i-- )
     {
        for( int j = b.size() - 1; j >= 0; j-- )
          {
             result[ i + j + 1 ] += ( b[ j ] - '0') * ( a[ i ] - '0' ); //single array to store intermediate values
          }
     }
   for( int i = a.size() + b.size() - 1; i >= 0; i-- ){
        if( result[ i ] >= 10 ){
             result[ i - 1 ] +=result[ i ] / 10;result[ i ] %= 10;
        }
   }
   cout << a << " * " << b << " = ";
   for( int i = 0; i < a.size() + b.size(); i++ ){
        cout << result[ i ];
   }
   cout << endl;
}
int main( void )
{
   string str1, str2 ;
   str1 = "99999999999999999999";str2 = "9985995948565498566";
   str1 = "20";str2 = "1000";
   product( str1, str2 );
   return 0;
}
