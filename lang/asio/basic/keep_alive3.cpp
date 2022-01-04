#include <asio.hpp>
#include <iostream>
#include <thread>

using work_guard_type = asio::executor_work_guard<asio::io_context::executor_type>;
int main()
{
    using namespace std::chrono_literals;
    asio::io_context io;

    work_guard_type work_guard(io.get_executor());
    io.post([&]()
            {
            std::cout << "post run()\n";
            });

    std::thread watchdog([&](){
        std::this_thread::sleep_for(10s);
        io.reset();
        std::cout << "watch dog reset\n";
        io.stop();
    });
    io.run();

    std::cout << "Watchdog exit after 10s\n";

    return 0;
}
