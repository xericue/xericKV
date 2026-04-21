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

    // set it up - in C this is usually done with getsockaddrinfo
    struct sockaddr_in address {};
    address.sin_family = AF_INET;
    address.sin_port = ntohs(8080); // network programming - big endian to little endian
    address.sin_addr.s_addr = INADDR_ANY; // IPv4/6
    
    int connection_port = connect(tcp_socket, (const struct sockaddr *)&address, sizeof(address));
    if (connection_port) {
        std::cout << "connection returned " << connection_port << " - error\n";
        exit(1);
    }
    
    char message[BUFSIZ] {"hello"};
    write(tcp_socket, message, strlen(message));

    char buf[BUFSIZ] {};
    ssize_t n {read(tcp_socket, buf, sizeof(buf))};
    if (n < 0) {
        std::cout << "read error\n";
        exit(1);
    }
    std::cout << "server says " << buf << '\n';
    close(tcp_socket);

    return 0;
}