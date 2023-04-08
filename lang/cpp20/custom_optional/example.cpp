#include <optional>
#include <iostream>

struct A
{
   std::string s;

  public:
   A(std::string str): s(std::move(str)), id {n++} { note("+ constructed"); }
   ~A() { note ("- destructed"); }
   A(const A &o): s(o.s), id {n++} {note("+ copy constructed"); }
   A(A &&o): s(std::move(o.s)), id{n++} {note("+ move constructed"); }

   A &operator=(const A &o)
     {
        s = o.s;
        note("+ copy assigned");
        return *this;
     }

   A &operator=(A &&o)
     {
        s = std::move(o.s);
        note("+ move assigned");
        return *this;
     }

  private:
   inline static int n {};
   int id {};
   void note(auto s) { std::cout << " " << s << " #" << id << std::endl; }
};
int main()
{
   std::optional<A> opt;
   std::cout << "Assign\n";
   opt = A("kldnflkdsnf");

   /*
    * Note that emplace() is more efficient than operator=() or emplace_back() for
    * constructing objects in optional objects because it avoids creating temporary
    * objects and copying or moving them into the optional object.
    *
    */
   std::cout << "Emplace\n";
   opt.emplace("Awesome");

   return 0;
}
