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

---
