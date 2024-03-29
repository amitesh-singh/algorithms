#include <iostream>
#include <memory> //for unique_ptr
//unique_ptr is the replacement of auto_ptr, don't use auto_ptr anymore.
//note: std::unique_ptr<> can't be passed by value, so it's usually moved around with
// the use of special function std::move()
using namespace std;

class Base
{
public:
virtual void foo() = 0;
virtual int getX() = 0;
};

class  Derived: public Base
{
    public:
    int x;
    Derived() = default;
    Derived(int x) {this->x = x;};
    void foo() override
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    int getX() override
    {
        return x;
    }
};

//pass by copy is not allowed.
void compute(std::unique_ptr<int> ptr)
{

}

int main()
{
    std::unique_ptr<int> ptr(new int); //ok
    //std::unique_ptr<int> ptr2 = new int; // not allowed
    std::unique_ptr<int> ptr2 {new int}; //ok
    std::unique_ptr<int> ptr3 = std::make_unique<int>();
    
    *ptr = 100;
    cout << *ptr << endl;
    //use ptr.get() or ptr to get the address.
    cout << ptr.get() << endl;

    // ptr = ptr2; //not allowed, copy constructor is disabled.
    ptr = std::move(ptr2); // ptr2 is now nullptr now.
    cout << *ptr << endl;
    *ptr = 10;
    //copy by value is not allowed
    //compute(ptr); //ERROR! copy by value is not allowed.
    compute(std::move(ptr));
    //ptr is invalid here
    // will crash since ptr is now nullptr.
    // std::cout << *ptr << std::endl;
    ptr.reset(new int(101)); // there is no need of temp variable, just reset and use it.
    //*ptr2 = 11; //Error! Seg Fault. ptr2 is now nullptr

    //for defining classes

    std::unique_ptr<Derived> derived (new Derived);
    std::unique_ptr<Derived> d2 = std::make_unique<Derived>();
    //using inheritance.
    std::unique_ptr<Base> base {new Derived};
    base->foo();
    
    std::unique_ptr<Base> b2 (new Derived);

    std::unique_ptr<Base> b3 = std::make_unique<Derived>();
    b3->foo();

    b3 = std::move(base);
    b3->foo();
    // {} initializer for arrays and classes
    std::unique_ptr<Base> b11 {new Derived{19}};
    std::unique_ptr<Base> b4 = std::make_unique<Derived>(10);
    
    cout << b4->getX() << endl;

    //defining an array
    auto arr = std::make_unique<int[]>(16);

    for (int i = 0; i < 16; ++i)
        arr[i] = i;
    for (int i = 0; i < 16; ++i)
        cout << arr[i] << ", ";
    cout << endl;

    //initializing unique_ptr
    std::unique_ptr<int[]> arr2 {new int[5]{1, 2, 3, 4, 5}};

    //custom deleter function
    auto deleter = [](int *x){
        cout << "deleting " << x << endl;
        delete x;
    };

    std::unique_ptr<int, void (*) (int *)> p(new int, deleter);

    return 0;
}
