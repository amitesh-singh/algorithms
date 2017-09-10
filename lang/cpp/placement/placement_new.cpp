#include <iostream>

using namespace std;

#define F cout << __PRETTY_FUNCTION__ << endl
static char mem[500];
class A
{
 public:
    int a;
    A() { F;}
    ~A() {F;}
};
int main()
{
   A *ptr = new (mem) A();

   ptr->~A();
   return 0;
}
