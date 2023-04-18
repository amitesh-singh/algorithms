#include <iostream>
#include <memory>

class device
{
  public:
      device(int id) {
           if (id == 2)
             throw std::runtime_error("device id can't be 2");
      }
      ~device() {
           std::cout << "~device()\n";
      }
};

class driver 
{
   std::unique_ptr<device> d1, d2;

  public:
    driver(int id1, int id2)
      {
         try {
              d1 = std::make_unique<device>(id1);
              d2 = std::make_unique<device>(id2);
         }catch (...) {
              d1.reset();
              d2.reset();
              throw;
         }
      }
    ~driver()
      {
         std::cout << "~device()\n";
      }
};

/*
Use the noexcept(false) specifier in the constructor declaration: This explicitly indicates that the constructor may throw exceptions. 
By default, C++ constructors are assumed to be noexcept(true), meaning they are not allowed to throw exceptions. However, you can override this by specifying noexcept(false).
*/
class meh
{
    public:
    meh(int val) noexcept(false)
    {
        if (val < 0) {
            throw std::runtime_error("val can't be negative");
        }
    }
};

int main()
{
   try {
      //  device d1(2);
      driver d(1, 2);
   } catch(std::exception &e) {
        std::cerr << e.what() << '\n';
   }

   try {
      meh m(-2);
   } catch(const std::exception &e) {
      std::cerr << e.what() << '\n';
   }

   return 0;
}
