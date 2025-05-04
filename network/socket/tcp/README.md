# Note On Socket Programmin
<br>

# Introduction

### Socket & Socket Programming Explanation:

Socket programming is a way of connecting two nodes on a network to communicate with each other. One socket/node listens on a particular port at an IP, while the other socket reaches out to the other to form the connection. So, **Sockets** allow communication between two different processes on the same or different machine. A socket is simply a file descriptor that enables remote communication.


### Client/Server Communication Explanation:

**Client/Server** communication involves two components, namely a client and a server. Usually multiple clients and one server for communication. Clients send requests to the server, and server respond to the clients' requests.

> SYN -> ACK + SYN -> ACK .

Client needs to know the server address to send request, also **client isn't on always** and initiates requests to the server whenever interested. But **server is always on** and if it won't, then when a client send a request, see an error(i.e., Connection Failed.), server is services requests from many clients, it doesn't initiate contact with any clients.


### Starting Steps & Use Sockets:
1. **Set a socket:** A combination of an IP address and a port number that acts as an endpoint for communication. For instance, *192.168.1.1:8009*, where the *192.168.1.1* is an IP and *8009* is a port number. Also socket types: **TCP Socket(Stream Socket)** and **UDP Socket(Datagram Socket)**.

2. **Send and receive the packets:** Write data from the socket(i.e., client request or server response) to the server socket, read data from the client socket(i.e., client request) and do stuff with the data(e.g., display a Web page.).

3. **Close the socket:** Don't forget to close the socket descriptor after all efforts.

---
<br>

# Typical Client Program

### Create A Socket

To create a communication endpoint, we use the `socket()` function. According to the `man` page in UNIX, this function creates an endpoint for communication and returns a file descriptor that refers to it. This descriptor is the lowest-numbered one not currently open for the process.
From what I've gathered (by reading the man pages and doing a bit of searching), when we call `socket()`, the OS creates something like a communication door that we can use to send or receive data. The OS returns a file descriptor (an integer) that represents this socket, so we can refer to it in later calls (like `connect()`, `send()`, or `recv()`). So, it returns **a socket descriptor** on success, **-1** on failure.

> `int socket(int domain, int type, int protocol);`
<br>

1. **sockfd:** An integer instance of `socket()` for use it in later calls.

2. **domain:** The `domain` argument specifies a communication domain; This selects the protocol family which will be used for communication. Usually use `AF_INET` or `AF_INET6`, where the `AF_INET` used for **IPv4** and `AF_INET6` used for **IPv6**. So it refers to *what kind of network we're using*.

3. **type:** The `type` argument specifies the communication semantics. Currently defined types include: `SOCK_STREAM`, `SOCK_DGRAM`, and `SOCK_RAW`. For more, check `man` page, since most of this document base on it. However, I'll use `SOCK_STREAM` which is used for **TCP** or use `SOCK_DGRAM` which is used for **UDP**. Nevertheless, it refers to *What kind of connection we're using*.

4. **protocol:** This argument specifies a particular protocol to be used with the socket. Normally only a single protocol exists to support a particular socket type within a given protocol family, in which case protocol can be specified as 0. Though, it refers to *which specific protocol to use*. However, when we set `domain = AF_INET` and `type = SOCK_STREAM`, the system already knows we probably mean **TCP**.


### Connect To Server
Before sending requests, we need to connect the client to the server. Use `connect()` system call to initiate a connection on a socket.
> `int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);`

It is used when the program wants to connect to another computer (or service) over a network using a socket.
1. **sockfd:** It is the socket the program is using.
2. **addr:** Which represents the destination (i.e., an IP address and port). The way it's formatted depends on the type of connection(e.g., IPv4 or IPv6) the socket is set up for.
3. **addrlen:** Tells the system how big the `addr` information is.

From what I've gathered (by reading the man pages and doing a bit of searching), when we call `connect()` we're actually connecting the socket referred to by the `sockfd` with the address specified by `addr` and the `addrlen` argument specifies the size of `addr`. Because our socket is a **SOCK_STREAM** which is used for **TCP**, when we call `connect()` it performs a 3-way handshake with the remote server and then a dedicated connection is established between the two machines :/ Then we can use `read()`, `recv()`, or `write()`, but we cannot send or receive data until this succeeds.


### Send And Receive Packets
Exchange data with the server. The steps:
1. Write data (i.e., request) **to** the server.
2. Read data (i.e., response) **from** the server.
3. Process the data (e.g., display a Web page or just a simple message).

### Close The Socket
This is the last step after socket creation, client connection with a server, and send/receive packets. So, don't forget to close the socket descriptor after the communication is complete.
> `close(sock_fd);`

`sock_fd` is an instance of the `socket()` system call where I talked about it in **Create A Socket** section.

---
