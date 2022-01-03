#include <asio.hpp>
#include <iostream>

using work_guard_type = asio::executor_work_guard<asio::io_context::executor_type>;
int main()
{
    asio::io_context io;

    work_guard_type work_guard(io.get_executor());

    io.run();

    std::cout << "Never reach here\n";

    return 0;
}