#include <iostream>
#include <memory>

class shared_test : public std::enable_shared_from_this<shared_test>
{
public:
    void print(bool recursive) {
        if (recursive) {
            shared_from_this()->print(false);
        }

        std::cout << "printing" << std::endl;
    }
};

int main()
{
   std::shared_ptr<shared_test> t1 = std::make_shared<shared_test>();
   t1->print(true);
   return 0;
}
