#include <iostream>
#include <boost/asio/io_service.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "Content.h"

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

const int BUFSIZE = 4096;
io_service ioservice;
tcp::endpoint tcp_endpoint {tcp::v4(), 1967};
tcp::acceptor tcp_acceptor {ioservice, tcp_endpoint};
char bytes[BUFSIZE];
string postdata = "";

void do_write(tcp::socket& tcp_socket, yield_context yield);

void do_read(tcp::socket& tcp_socket, yield_context yield) {
    postdata.clear();
    size_t length = tcp_socket.async_read_some(buffer(bytes), yield);
    bytes[length] = '\0';
    // GET
    if (bytes[0] == 'G' && bytes[2] == 'T' && bytes[4] == '/') {
        cout << "GET request" << endl;
    }
    // POST
    unsigned int cl = 0;
    string cls = "";
    if (bytes[0] == 'P' && bytes[2] == 'S' && bytes[4] == ' ' && bytes[5] == '/') {
        for (int j = 0; j < BUFSIZE || bytes[j] == '\0'; ++j) {
            // If Content-Length:
            if (bytes[j] == 'C' && bytes[j+8] == 'L' && bytes[j+14] == ':') {
                for (int k = (j + 16);; ++k) {
                    if (bytes[k] == '\r' || bytes[k] == '\0') {
                        break;
                    }
                    cls.push_back(bytes[k]);
                }
                cl = (unsigned int) stoul(cls);
                cout << "content-length: " << cl << endl;
            }
        }
        cout << endl << "POST request" << endl << endl;
    }
    cout << "do_read() START, size: " << length << ", input: " << endl << endl << bytes << endl << endl << "do_read() END" << endl;

    for (auto j = (length - cl); j < length; ++j) {
        postdata.append(1, bytes[j]);
    }

    spawn(ioservice, [&] (yield_context yield) { do_write(tcp_socket, yield); });
}

void do_write(tcp::socket& tcp_socket, yield_context yield) {
    Content content;
    string data = content.getContent();
    cout << "do_write(), postdata: " << postdata << endl;
    async_write(tcp_socket, buffer(data), yield);
    tcp_socket.shutdown(tcp::socket::shutdown_send);
}

void do_accept(yield_context yield) {
    for (int i = 0; i < 5; ++i) {
        tcp::socket *tcp_socket = new tcp::socket {ioservice};
        tcp_acceptor.async_accept(*tcp_socket, yield);
        spawn(ioservice, [&] (yield_context yield) { do_read(*tcp_socket, yield); });
//        spawn(ioservice, [&] (yield_context yield) { do_write(*tcp_socket, yield); });
    }
}

int main() {
    cout << "Hello, World!" << endl;
    tcp_acceptor.listen();
    spawn(ioservice, do_accept);
    ioservice.run();
    return 0;
}
