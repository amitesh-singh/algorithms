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
   std::sort(fruits.begin(), fruits.end(), NoCase{});
   cout << "custom function sorted: ";
   for (int i = 0; i < fruits.size(); ++i)
     {
        cout << fruits[i] << ",";
     }
   cout << endl;

   //we can use lambda functions too 
   std::vector<int> v{9, 23, 13, -9, 23, 32};
   //descending order.
   //u can declare lambda function like  this as well.
   // auto mygreater = [](const int &lhs, const int &rhs)-> bool { return lhs > rhs; };

   std::sort(v.begin(), v.end(), [](const int &lhs, const int &rhs)-> bool {
      return lhs > rhs;
   });

   for(auto &x:v)
      std::cout << x << ", ";
   std::cout << std::endl;

   auto mylesser = [](const int &lhs, const int &rhs)-> bool { return lhs < rhs; };
   std::sort(begin(v), end(v), mylesser);
   for(auto &x:v)
      std::cout << x << ", ";
   std::cout << std::endl;
   
   return 0;
}

