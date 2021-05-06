/*
 *Semantically similar to using a typedef however, type aliases with using are easier to read and are compatible with templates.

template <typename T>
using Vec = std::vector<T>;
Vec<int> v; // std::vector<int>

using String = std::string;
String s {"foo"};
*/

#include <iostream>

using namespace std;

using String = std::string;

class BigNameClass
{
 public:
    BigNameClass(String name)
      {
         cout << name << endl;
      }
};

using BNC = BigNameClass;

//defining function ptr
typedef int (*process)(void *); //old way
using newprocess = int (*)(void *);

int init_process(void *)
{
   cout << __PRETTY_FUNCTION__ << endl;
   return 1;
}

int main()
{
   String ami("Amitesh Singh");
   cout << ami << "\n";

   //can be used for class too.
   //
   BNC bnc(ami);

  
   newprocess init = init_process;
   cout << init_process(nullptr);


   return 0;
}

