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
    threadpool tpool;

    tpool.start();
    /**
    for (int i = 0; i < 10; ++i)
    {
        tpool.addJob(doJob);
    }
    */
    myfuture<void> fobj2;
    myfuture<void> fobj[3];
    int x = 0;
    tpool.addJob(std::bind(setNum, std::ref(x)), fobj2);
    for (int i = 0; i < 3; ++i)
      tpool.addJob(doJob, fobj[i]);
    //waiting for the result
    fobj2.get();
    std::cout << "x= " << x << std::endl;
    tpool.addJob(std::bind(setNum, std::ref(x)), fobj2);
    fobj2.get();
    std::cout << "x= " << x << std::endl;
    while (1)
    {
        std::cout << "main: idle..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(6));
    }
    tpool.end();
    return 0;
}
