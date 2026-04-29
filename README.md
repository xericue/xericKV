# Write-Heavy Database Engine in C++

# Project Overview
This will turn into a write-heavy database implemented from scratch in C++. I previously made this in Python for a weekend project, so I will be migrating its features here with the following checklist:

- [ ] working KV storage engine (get, set, del components)
- [ ] write ahead log (WAL)
- [ ] MemTable
- [ ] SSTables for flushing to disk
- [ ] LSM-Tree (Log-Structured Merge Tree)
- [ ] Tombstone class to mark deleted keys
- [ ] persistent memory storage
- [ ] interactive CLI/REPL
- [ ] thread safety
- [ ] basic network programming for a client/server model
- [ ] modern C++20 features

While my initial goals for this project were silly (set "bruh" : "gurt", set "dylan": "goat"), I hope to scale this in the future, possibly to see applications of high-frequency trading or a distributed engine!

# Future Goals
- [ ] thread pool for concurrency
- [ ] migrate from a sorted list with binary search in the memtable to a skip list (possible benchmarks against Google's LevelDB and Meta's RocksDB)
- [ ] more levels to the LSM tree
- [ ] write benchmark script (sets/gets/range at 1k, 10k, 100k entries)
- [ ] write more robust unit tests by hand
- [ ] implement Raft algorithm
- [ ] add sharding
- [ ] bloom filter

### Future Future Goals

- [ ] add an async Rust client library with tokio that connects to the server through TCP
- [ ] possibly explore a lock-free data structure?
- [ ] look into database indexing?...
- [ ] implement MVCC (multi-version concurrency control) - instead of locking on writes, create a new version of a key w/ timestamp, and reads take a snapshot of the database)
- [ ] benchmark ops/sec against RocksDB/LevelDB 

# Project Workflow

The major concepts here are the write-ahead log (WAL), memory table (MemTable), (SSTable), and the log-structured merge tree (LSM tree). We want persistence, fast access, and accurate sorting. 

```
- set through CLI -> WAL write and MemTable initialization
- if MemTable is full: flush into an SSTable, set a WAL checkpoint
- if too many SSTables - compact()

- get through CLI -> check MemTable
- if found - return from MemTable, continue CLI loop
- if not, go check the SSTables (icky disk reading)
- if not found at all, return None
```

# Original Notes Below

### Client/Server Model

The first goal here is to create a `client-server` model, so, naturally, we'll create a `client` and a `server` - `client.cpp` and `server.cpp`. `man ip.7` tells one what libraries are necessary for `Linux IPv4 protocol implementation.` The base idea is that the `server` creates a `socket` and binds it to a port (say, port 8080. Many online services follow conventions of ports; it can be anything). a `client` will then try to connect to port 8080 as the server listens to that connection. **the `client` reaches out to the `server`, and the `server` listens to that outreach.**

### Binding

when a process/server wants to receive new incoming packets or connections, it should bind its socket to a `local interface address`
- only one IP (internet protocol) socket may be bound to any given local address PAIR: `(address, port)`