#include <iostream>

class Singleton
{
    static Singleton *_instance;
    Singleton() = default;

    public:
    static Singleton *getInstance()
    {
        if (!_instance) _instance = new Singleton();
        return _instance;
    }
};

Singleton *Singleton::_instance = nullptr;

int main()
{
    Singleton *obj = Singleton::getInstance();
    std::cout << obj << std::endl;
    std::cout << Singleton::getInstance() << std::endl;

    return 0;
}