#include <iostream>
#include <thread>
#include <latch>
#include <string>

const int num_workers = 5;

int main()
{
    std::latch construction_latch(num_workers);

    std::cout << "construction work is starting..\n";
    for (int i = 0; i < num_workers; ++i) {
        std::string task = "Phase: " + std::to_string(i + 1);
        std::thread([id = i, task, &latch = construction_latch]() {
            std::cout << "Worker " << id << " is starting the " << task << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "Worker " << id << " has completed the " << task << std::endl;
            latch.count_down();
        }).detach();
    }
    /* wait for all workers to complete their tasks */
    construction_latch.wait();

    std::cout << "Constuction project is finished.\n";

    return 0;
}