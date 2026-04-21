In-memory KV store in progress.

- [x] basic network programming for a client/server model
- [ ] event loop for multiple socket connections
- [ ] `GET`, `SET`, `DEL` components to make this thing functional baby!
- [ ] the actual hash table to store components in memory
- [ ] thread pool for concurrent connections


future goals
- [ ] implement Raft algorithm
- [ ] write-ahead logs
- [ ] add sharding
- [ ] eventually move to Rust

# The Basic Idea

The first goal here is to create a `client-server` model, so, naturally, we'll create a `client` and a `server` - `client.cpp` and `server.cpp`. `man ip.7` tells one what libraries are necessary for `Linux IPv4 protocol implementation.` The base idea is that the `server` creates a `socket` and binds it to a port (say, port 8080. Many online services follow conventions of ports; it can be anything). a `client` will then try to connect to port 8080 as the server listens to that connection. **the `client` reaches out to the `server`, and the `server` listens to that outreach.**

Databases would more so use B-trees or LSM-trees for internal implementation; we will be using an AVL tree because it keeps in mind in-memory implementation; however, as I begin to learn about distributed systems and the lauded /Raft consensus algorithm/, things may change. As I grow as an engineer, I hope to learn about how the tools people have developed in the past influence our present and future, like Redis.

### Binding

when a process/server wants to receive new incoming packets or connections, it should bind its socket to a `local interface address`
- only one IP (internet protocol) socket may be bound to any given local address PAIR: `(address, port)`

### Namespace

