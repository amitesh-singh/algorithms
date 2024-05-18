#include<iostream>
#include<set>

using namespace std;

//Sets are usually implemented as Red-Black Tree.

class client
{
 public:
    int id;
    client(int i):id (i) {}
};

struct clientcomp
{
   //the set comparator should be const, or else it won't compile
   bool operator()(const client &lhs, const client &rhs) const
     {
        return lhs.id < rhs.id;
     }
};

void print(std::set<int> &s)
{
   for (auto &x: s)
     std::cout << x << ", ";
   std::cout << std::endl;
}

int main()
{
  //elements are in sorted order, in descending order
   std::set<int, std::greater<int>> S; // or std::set<int, std::greater<>> S; //CDAT

   S.insert(1);
   S.insert(2);
   S.insert(12);
   S.insert(0);

   for (auto &x: S)
     std::cout << x << ", ";
   std::cout << std::endl;

   //lower bound
   auto index = S.lower_bound(2);

   if (index != S.end())
    {
        std::cout << "lower_bound(2): " << *index << std::endl;
    }

   std::set<client, clientcomp> s1;
   s1.insert(client(10));
   s1.insert(client(-1));
   s1.insert(client(0));
   s1.insert(client(9));

   for (auto &x: s1)
     std::cout << x.id << ", ";
   std::cout << std::endl;

     {
        std::set<int> s;
        for (int i = 0; i < 5; ++i)
          s.insert(i*10);

        print(s);

        std::cout << "inserting 99 at the head\n";
        auto itr = s.begin();
        //insert at the begining.
        s.insert(itr, 99);
        print(s);

        //remember in set, we can only have unique elements.
        int arr[] {23, 34, 56, 56};
        s.insert(arr, arr + 4);
        print(s);

        //erasing 23
        std::cout << "deleting 23\n";
        s.erase(23);
        print(s);

        s.empty() ? std::cout << "set is empty\n" : std::cout << "set is not empty\n";
        std::cout << "size = " << s.size() << " max_size = " << s.max_size() << std::endl;

        //find 56
        itr = s.find(56);
        if (itr != s.end())
          std::cout << "found " << *itr << std::endl;

        //how many times 56 is present in the set?
        int rep = s.count(56);
        std::cout << "56 is present " << rep << " times.\n";
        s.insert(56);

        rep = s.count(56);
        std::cout << "56 is present " << rep << " times.\n";

        std::cout << "clearing the set\n";
        s.clear();

        s.empty() ? std::cout << "set is empty\n" : std::cout << "set is not empty\n";
     }


   return 0;
}
