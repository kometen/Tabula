#include <iostream>
#include <boost/asio/io_service.hpp>
//#include <boost/asio/read.hpp>
#include <boost/asio/read_until.hpp>
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
char additional_bytes[BUFSIZE];
string postdata = "";

void do_write(tcp::socket& tcp_socket, yield_context yield);

void do_read(tcp::socket& tcp_socket, yield_context yield) {
    auto is_post = false, is_get = false;
    postdata.clear();
    size_t length = tcp_socket.async_read_some(buffer(bytes), yield);
    bytes[length] = '\0';
    // GET
    if (bytes[0] == 'G' && bytes[2] == 'T' && bytes[4] == '/') {
        is_post = false;
        is_get = true;
        cout << "GET request" << endl;
    }
    // POST
    unsigned int cl = 0;
    string cls = "";

    if (bytes[0] == 'P' && bytes[2] == 'S' && bytes[4] == ' ' && bytes[5] == '/') {
        is_post = true;
        is_get = false;
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

    // If form data is arriving in a separate ip package.
    if (is_post && bytes[length] == '\0' && bytes[length-1] == '\n' && bytes[length-2] == '\r') {
        size_t additional_length = tcp_socket.async_read_some(buffer(additional_bytes), yield);
        // Move back and overwrite delimiter and copy.
        --length;
        for (auto i = 0; i < additional_length; ++i) {
            bytes[++length] = additional_bytes[i];
        }
        bytes[++length] = '\0';
    }

    for (auto j = (length - cl); j < length; ++j) {
        postdata.append(1, bytes[j]);
    }

    cout << "do_read() START, size: " << length << endl << "inputXX" << bytes << "XXdo_read() END" << endl;

    spawn(ioservice, [&] (yield_context yield) { do_write(tcp_socket, yield); });
}

void do_write(tcp::socket& tcp_socket, yield_context yield) {
    Content content;
    content.setPostdata(postdata);
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
