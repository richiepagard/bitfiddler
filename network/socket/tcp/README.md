# Note On Socket Programming

# Introduction

- ### Socket & Socket Programming Explanation:

Socket programming is a way of connecting two nodes on a network to communicate with each other. One socket/node listens on a particular port at an IP, while the other socket reaches out to the other to form the connection. So, **Sockets** allow communication between two different processes on the same or different machine. A socket is simply a file descriptor that enables remote communication.

- ### Client/Server Communication Explanation:
**Client/Server** communication involves two components, namely a client and a server. Usually multiple clients and one server for communication. Clients send requests to the server, and server respond to the clients' requests.

> SYN -> ACK + SYN -> ACK .

Client needs to know the server address to send request, also **client isn't on always** and initiates requests to the server whenever interested. But **server is always on** and if it won't, then when a client send a request, see an error(i.e., Connection Failed.), server is services requests from many clients, it doesn't initiate contact with any clients.

- ### Starting Steps & Use Sockets:
**1- Set a socket:** A combination of an IP address and a port number that acts as an endpoint for communication. For instance, *192.168.1.1:8009*, where the *192.168.1.1* is an IP and *8009* is a port number. Also socket types: **TCP Socket(Stream Socket)** and **UDP Socket(Datagram Socket)**.

**2- Send and receive the packets:** Write data from the socket(i.e., client request or server response) to the server socket, read data from the client socket(i.e., client request) and do stuff with the data(e.g., display a Web page.).

**3- Close the socket:** Don't forget to close the socket descriptor after all efforts.

---
