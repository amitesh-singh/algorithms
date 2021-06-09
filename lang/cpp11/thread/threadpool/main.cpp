#include "threadpool.h"
#include <iostream>
#include <chrono>

void doJob()
{
    std::cout << "id: " << std::this_thread::get_id() << "-> doing an importand job" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "id: " << std::this_thread::get_id() << "-> finished the job" << std::endl;
}

int main()
{
    threadpool<2> tpool;

    tpool.start();
    for (int i = 0; i < 10; ++i)
    {
        tpool.addJob(doJob);
    }
    while (1)
    {
        std::cout << "main: idle..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(6));
    }
    tpool.end();
    return 0;
}
