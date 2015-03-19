#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Usage of sort() with vector<string> 
// 1. without custom comparator example. //std::less is getting used
// instead.
// 2. with custom comparator example

struct NoCase
{
   bool operator()(const string &lhs, const string &rhs)
     {
        return (strcmp(lhs.c_str(), rhs.c_str()) < 0);
     }
};

int main()
{
   vector<string> fruits;

   fruits.push_back("Apple");
   fruits.push_back("Orange");
   fruits.push_back("Banana");

   for (int i = 0; i < fruits.size(); ++i)
     {
        cout << fruits[i] << ",";
     }
   cout << endl;

   //apply std::sort();
   //std::less is applied here.
   std::sort(fruits.begin(), fruits.end());
   cout << "Sorted: ";
   for (int i = 0; i < fruits.size(); ++i)
     {
        cout << fruits[i] << ",";
     }
   cout << endl;

   //lets write your own comarator functor.
   std::sort(fruits.begin(), fruits.end(), NoCase());
   cout << "custom function sorted: ";
   for (int i = 0; i < fruits.size(); ++i)
     {
        cout << fruits[i] << ",";
     }
   cout << endl;

   return 0;
}

