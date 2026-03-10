#include <sys/socket.h>
#include <string>
#include <iostream>

int main() {
    // AF_INET = specify IPv4
    // SOCK_STREAM = specifies TCP socket type because TCP provides a straight
                //   connection-oriented data transfer (stream -> packets)
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    // error handling
    if (fd == 0) {
        printf("socket returned %d - error\n", fd);
        abort();
    }

    

    return 0;
}