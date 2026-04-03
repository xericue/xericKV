# TCP, socket programming

you'll need to include quite a few libraries in order to start programming with actual sockets and servers. the goal here is to create a `client-server` model, so, naturally, we'll create a `client` and a `server` - `client.cpp` and `server.cpp`. `man ip.7` tells one what libraries are necessary for `Linux IPv4 protocol implementation.`

the base idea is that the `server` creates a `socket` and binds it to a port (say port 67). a `client` will then try to connect to port 67 as the server listens to that connection. **the `client` reaches out to the `server`, and the `server` listens to that outreach.**

## binding

when a process/server wants to receive new incoming packets or connections, it should bind its socket to a `local interface address`
- only one IP (internet protocol) socket may be bound to any given local address PAIR: `(address, port)`

## Namespace

