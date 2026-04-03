#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <iostream>

int main() {

    // open an unitialized socket, IPv4 + TCP protocol
    int tcp_socket {socket(AF_INET, SOCK_STREAM, 0)};
    // error handling
    if (tcp_socket == 0) {
        std::cout << "socket returned " << tcp_socket << " - error\n";
        abort();
    }

    // bind socket to an address 
    // bind(tcp_socket, address)
    
    // listen
    
    // setsockopt() - ingests the file descriptor tcp_socket - set (theres also get)
    // options on sockets
    int options {1};
    setsockopt(tcp_socket, SOL_SOCKET, SO_REUSEADDR, &options, sizeof(options));
    
    // setting socket options to reuse sockets, beginning to create the struct 
    // for the socket address for correct connection
    struct sockaddr_in addr {

    };
    
    // int bind(fd, const struct sockaddr *addr, socklen_t addrlen); 
    
    
    return 0;
}