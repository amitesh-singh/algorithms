#include <iostream>
#include <mutex>
#include <thread>

void f(const std::string &msg)
{
    //must be global or static storage
    static std::once_flag flag;
    std::call_once(flag, [&msg](){std::cout << msg << "\n";} );
}

void f2(const std::string &msg)
{
    static thread_local std::once_flag onetimecall_flag;

    std::call_once(onetimecall_flag, [&msg](){std::cout << msg << "\n";} );
}

bool meh() {
 double x;
 auto f = [x=1]() -> decltype(x) {return 1.1;};
 return f() > 1; // A
}
int main()
{
    std::string msg = "from main";
    f(msg);
    f(msg);
    msg = "from thread";

    {
        std::thread t(f, std::ref(msg));
        t.join();
    }

    {
        std::thread t(f, std::ref(msg));
        t.join();
    }
    std::cout << "use of thread_local\n";

    msg = "from main";
    f2(msg);
    f2(msg);
    msg = "from thread";

    {
        std::thread t(f2, std::ref(msg));
        t.join();
    }
    {
        std::thread t(f2, std::ref(msg));
        t.join();
    }
     {
        std::thread t(f2, std::ref(msg));
        t.join();
    }
    std::cout << meh() << std::endl;
    
    return 0;
}