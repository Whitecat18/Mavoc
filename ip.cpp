#include <iostream>
#include <boost/asio.hpp>

int main() {
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::resolver resolver(io_service);
    boost::asio::ip::tcp::resolver::query query(boost::asio::ip::host_name(), "");
    boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(query);
    boost::asio::ip::tcp::resolver::iterator end;

    while (it != end) {
        boost::asio::ip::tcp::endpoint ep = *it++;
        std::string ip = ep.address().to_string();
        if (ip.find(':') == std::string::npos && ip != "127.0.0.1") {
            std::cout << "Local IP address: " << ip << std::endl;
            break;
        }
    }

    return 0;
}
