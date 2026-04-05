#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

static void read_write(int socket) {
    char read_buffer[64] {}; // read buffer
    ssize_t n = read(socket, read_buffer, sizeof(read_buffer));

    if (n < 0) {
        std::cout << "read error\n";
        return;
    }

    std::cout << "client says " << read_buffer << '\n';

    char write_buffer[64] {"yea bro\n"};
    write(socket, write_buffer, sizeof(write_buffer));
}

int main() {
    
    // open an unitialized socket, IPv4 + TCP protocol
    int tcp_socket {socket(AF_INET, SOCK_STREAM, 0)};
    // error handling
    if (tcp_socket < 0) {
        std::cout << "socket returned " << tcp_socket << " - error\n";
        exit(1);
    }

    // bind socket to an address 

    // setsockopt() - ingests the file descriptor tcp_socket - set (theres also get)
    // options on sockets
    int options {1};
    setsockopt(tcp_socket, SOL_SOCKET, SO_REUSEADDR, &options, sizeof(options));
    
        // setting socket options to reuse sockets, beginning to create the struct 
    // for the socket address for correct connection
    // struct sockaddr_in {
    //     uint16_t sin_family;
    //     uint16_t sin_port;
    //     struct in_addr sin_addr;
    // };

    // struct in_addr {
    //     uint32_t s_addr;
    // };

    struct sockaddr_in address = {};
    address.sin_family = AF_INET;
    address.sin_port = htons(8080); // port 6767
    address.sin_addr.s_addr = htonl(0); // wildcard IP 0.0.0.0
    
    // sockfd (tcp_socket), const struct sockaddr *addr, socklen_t);

    int bound_socket = bind(tcp_socket, (const sockaddr *)&address, sizeof(address));

    if (bound_socket) {
        std::cout << "bind returned " << bound_socket << " - error\n";
        exit(1);
    }
    
    // listen()
    // this actually creates the socket - OS handles TCP handshake; places connections in a queue
    bound_socket = listen(tcp_socket, SOMAXCONN); // macro for #define SOMAXCONN 4096; size of the queue in bits(???)

    // returns 0 on success, -1 for errors
    if (bound_socket) {
        std::cout << "listen returned " << bound_socket << " - error\n";
        exit(1);
    }

    /////////////////
    // accepting connections in an event loop
    while (true) {
        // process each client connection
        // accept()
        struct sockaddr_in client = {};
        socklen_t client_len = sizeof(client);

        int client_file_descriptor = accept(tcp_socket, (struct sockaddr *)&client, &client_len);
        if (client_file_descriptor == -1) {
            // std::cout << "accept returned " << bound_socket << " - error\n";
            // exit(1);
            continue;
        }

        // do whatever here!
        read_write(client_file_descriptor);
        close(client_file_descriptor);
    }

    
    return 0;
}