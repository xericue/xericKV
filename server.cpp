#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <cassert>
#include "server.h"

static void read_write(int fd) {
    char buf[BUFSIZ] {}; // read buffer
    ssize_t n = read(fd, buf, sizeof(buf) - 1);
    // read/write or send/recv
    if (n < 0) {
        std::cout << "read() error\n";
        return;
    }

    std::cout << "client says " << buf << '\n';

    char write_buffer[BUFSIZ] {"yo\n"};
    write(fd, write_buffer, sizeof(write_buffer)); // it writes back through fd?
}

int one_request(int socket) {

}

static int32_t read_full(int fd, char *buf, size_t size) {
    while (size > 0) {
        ssize_t read_vector = read(fd, buf, size);
        if (read_vector <= 0)
            return 1;
        assert((size_t)read_vector <= size);
        size -= (size_t)read_vector;
        buf += read_vector;
    }
    return 0;
}

static int32_t write_all(int fd, const char *buf, size_t size) {
    while (size > 0) {
        
    }

    return 0;
}

int main() {
    // i should probably be calling getsockaddrinfo here huh
    // open an unitialized socket, IPv4 + TCP protocol
    int tcp_socket {socket(AF_INET, SOCK_STREAM, 0)};
    // error handling
    if (tcp_socket < 0) {
        std::cout << "socket returned " << tcp_socket << " - error\n";
        exit(1);
    }

    // bind socket to an address 

    // setsockopt() - ingests the file descriptor tcp_socket
    int options {1};
    setsockopt(tcp_socket, SOL_SOCKET, SO_REUSEADDR, &options, sizeof(options));
    

    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET; // TCP
    addr.sin_port = htons(8080); // port 8080 w/ network endianness
    addr.sin_addr.s_addr = INADDR_ANY; // read IPv4/v6 
    // sockfd (tcp_socket), const struct sockaddr *addr, socklen_t);

    int bound_socket = bind(tcp_socket, (const sockaddr *)&addr, sizeof(addr));

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

        // because the last param of accept ingests an address/ptr
        int fd = accept(tcp_socket, (struct sockaddr *)&client, &client_len); // nullptr nullptr?
        if (fd < 0) continue; // we can actually just continue because EVENTUALLY
        // itll connect

        // do whatever here!

        read_write(fd);
        // while (true) {
        //     int32_t err = one_request(fd); // signed int 32 bits
        //     if (err) break;
        // }
        close(fd);
    }

    
    return 0;
}