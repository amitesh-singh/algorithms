#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator> //for ostream_iterator
#include <cstdio>

using namespace std;

struct SortFunc
{
   inline bool operator() (const int &lhs, const int &rhs)
     {
        return lhs < rhs;
     }
};

struct Object
{
   string _name;
   Object(string name): _name(name) {}
   bool operator <(const Object &rhs)
   {
      int lval = atoi(_name.c_str());
      int rval = atoi(rhs._name.c_str());
      return lval < rval;
   }
};

ostream &operator<<(std::ostream &s, const Object &obj)
{
   return s << obj._name;
}

struct StringSort
{
   inline bool operator()(const string &lhs, const string &rhs)
     {
        //  return strcmp(lhs.c_str(), rhs.c_str());
        return lhs < rhs;
     }
};

int main()
{
   vector<int> v;
   srand(time(nullptr));

   for (int i = 0; i < 100; ++i)
     {
        v.push_back(rand() % 123);
     }

   std::sort(v.begin(), v.end(), SortFunc());
   //copy the vector data to stdout aka ostream
   std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
   cout << "\n";

   vector<string> strList;
   for (int i = 0; i < 100; ++i)
     {
        char buf[15];
        sprintf(buf, "%d", i);
        strList.push_back(string(buf));
     }

   std::sort(strList.begin(), strList.end(), StringSort());
   std::copy(strList.begin(), strList.end(),
             ostream_iterator<string>(cout, ", "));
   cout << "\n";

   vector<Object> objList;
   for (int i = 0; i < 10; ++i)
     {
        char buf[115];
        sprintf(buf, "%d", rand() % 119);
        objList.push_back(Object(string(buf)));
     }
   std::cout << "objects: \n";
   std::sort(objList.begin(), objList.end());
   std::copy(objList.begin(), objList.end(),
             ostream_iterator<Object>(cout, ", "));
   cout << "\n";

   return 0;
}
