#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main() {
    // this is the script that will be calling/making a connection to the server
    // you will always need at least one listening socket to open the port(?)
    // but then you can create more than one connection depending on what you
    // want to do
    int tcp_socket {socket(AF_INET, SOCK_STREAM, 0)};
    if (tcp_socket < 0) {
        std::cout << "socket returned " << tcp_socket << " - error\n";
        exit(1);
    }

    struct sockaddr_in address {};
    address.sin_family = AF_INET;
    address.sin_port = ntohs(6767); // network programming - big endian to little endian
    address.sin_addr.s_addr = ntohl(INADDR_LOOPBACK);
    
    int connection_port = connect(tcp_socket, (const struct sockaddr *)&address, sizeof(address));
    if (connection_port) {
        std::cout << "connection returned " << connection_port << " - error\n";
        exit(1);
    }
    
    char message[BUFSIZ] {};

    while (true) {
        std::cout << "yea yea write your message already\n";
        std::cin >> message;
        write(tcp_socket, message, strlen(message));
        char read_buffer[64] {};

    ssize_t n = read(tcp_socket, read_buffer, sizeof(read_buffer));
    if (n < 0) {
        std::cout << "read error\n";
        exit(1);
    }

    std::cout << "server says " << read_buffer << '\n';
    }
    
    /*
    std::cout << "yea yea write your message already\n";
    std::cin >> message;
    
    write(tcp_socket, message, strlen(message));
    */
    

    // char read_buffer[64] {};

    // ssize_t n = read(tcp_socket, read_buffer, sizeof(read_buffer));
    // if (n < 0) {
    //     std::cout << "read error\n";
    //     exit(1);
    // }

    // std::cout << "server says " << read_buffer << '\n';
    close(tcp_socket);

    return 0;
}