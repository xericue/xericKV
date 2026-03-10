#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <iostream>

int main() {
    // AF_INET = specify IPv4
    // SOCK_STREAM = opens a stream socket (TCP):
    // specifies TCP socket type because TCP provides a straight
    // connection-oriented data transfer (stream -> packets)
    // i.e. IPv4+TCP protocol is what we define here
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    // error handling
    if (fd == 0) {
        std::cout << "socket returned " << fd << " - error\n";
        abort();
    }

    // next steps: bind and listen
    // right now, our socket is TCP but typeless. we will make a listening socket
    // socket exists in a name space but has no address assigned to it
    
    // so we need to specify an address with addr
    // server creates a socket, binds a NAME to a socket

    // setsockopt() - ingests the file descriptor fd - set (theres also get)
    // options on sockets
    int options = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &options, sizeof(options));
    
    struct sockaddr_in addr {

    };
    
    // int bind(fd, const struct sockaddr *addr, socklen_t addrlen); 
    

    return 0;
}