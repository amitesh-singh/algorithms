#include <future>
#include <thread>
#include <cassert>
#include <iostream>

class Work {
    private:
        int value ;
    public:
        Work() : value(42) {}
        auto spawn()
          { return std::async( [=]()->int{ return value ; }); }
        ~Work() {
             std::cerr << "~Work()\n";
        }
};

auto foo()
{
   Work tmp ;
   return tmp.spawn();
   // The closure associated with the returned future
   // has an implicit this pointer that is invalid.
}

int main()
{
   auto f = foo();
   f.wait();
   // The following fails due to the
   // originating class having been destroyed
   assert( 42 == f.get() );
   return 0 ;
}
