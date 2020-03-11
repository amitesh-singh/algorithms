#include<iostream>
#include <list>

class A
{
   int id;
 public:
   A() = default;
   A(int x): id(x) {}
   bool operator <(const A &rhs)
     {
        return id < rhs.id;
     }

   int getId() const { return id; }
};

struct AComparator
{
   bool operator()(const A&lhs, const A &rhs)
     {
        return rhs.getId() < lhs.getId(); //descending order
     }
};

int main()
{
   std::list<A> l = {
        A(10),
        A(1),
        A(-1),
        A(0),
        A(100)
   };
   //note: for std::list<A *>, operator < won't get called

   //operator < is called
   l.sort();

   for(auto i: l)
     std::cout << i.getId() << ", ";
   std::cout << std::endl;

   l.sort(AComparator());
   for(auto i: l)
     std::cout << i.getId() << ", ";
   std::cout << std::endl;

   //lambda fucntion
   l.sort([](const A &lhs, const A &rhs)->bool {
          return rhs.getId() > lhs.getId(); //descending order
          });
   for(auto i: l)
     std::cout << i.getId() << ", ";
   std::cout << std::endl;

   return 0;
}

