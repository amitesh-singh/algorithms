#include <asio.hpp>
#include <iostream>

class udpclient
{   
    asio::io_context &io_;
    asio::ip::udp::socket socket;
    asio::ip::udp::endpoint endpoint;
    public:
    udpclient(asio::io_context &io, std::uint16_t port): io_(io), endpoint(asio::ip::udp::v4(), port),
        socket(io, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0))
    {

    }

    ~udpclient()
    {
        socket.close();
    }

    void send(const std::string &msg)
    {
        socket.send_to(asio::buffer(msg, msg.size()), endpoint);
    }
};

int main()
{
    asio::io_context io;

    udpclient client(io, 15001);

    client.send("Hello World");
    io.run();
    return 0;
}
