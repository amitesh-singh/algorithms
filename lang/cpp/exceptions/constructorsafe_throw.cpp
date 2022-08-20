#include <iostream>
#include <memory>

class device
{
  public:
      device(int id) {
           if (id == 2)
             throw std::runtime_error("device id can't be 2");
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
              throw;
         }
      }
    ~driver()
      {
         std::cout << "~device()\n";
      }
};
int main()
{
   try {
        device d1(2);
   } catch(std::exception &e) {
        std::cerr << e.what() << '\n';
   }

   return 0;
}
