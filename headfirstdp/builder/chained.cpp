//refer https://en.wikipedia.org/wiki/Fluent_interface#C++
//
//
//
//http://www.spuriousthoughts.com/2012/11/06/chaining-setters-in-c-builder-pattern
//
//

#include <iostream>

class person
{
   std::string name;
   int age;
  public:
   void print()
        {
           std::cout << "name: " << name << " age: " << age << '\n';
        }
   friend class personbuilder;
};

class personbuilder
{
   person p;
public:
   personbuilder() {}
   //these are called fluent APIs
   personbuilder &withName(std::string &&n)
   {
      p.name = std::move(n);
      return *this;
   }

   //these are called fluent APIs
   personbuilder &withAge(int age)
   {
      p.age = age;
      return *this;
   }

   person build()
   {
      return p;
   }
};

int main()
{
   person ami = personbuilder().withName("ami").withAge(10).build();
   ami.print();

   return 0;
}
