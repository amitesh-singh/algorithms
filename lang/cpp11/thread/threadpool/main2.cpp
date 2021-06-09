#include "threadpool_with_wait.h"
#include <iostream>
#include <chrono>

void doJob()
{
    std::cout << "id: " << std::this_thread::get_id() << "-> doing an importand job" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "id: " << std::this_thread::get_id() << "-> job is finished" << std::endl;
}

void setNum(int &x)
{
    std::cout << "id: " << std::this_thread::get_id() << "-> doing an importand job" << std::endl;

    x++;
    std::cout << "setting x\n";
    std::cout << "id: " << std::this_thread::get_id() << "-> job is finished" << std::endl;
}

int main()
{
    threadpool<10> tpool;

    tpool.start();
    tpool.end();
    return 0;
}
