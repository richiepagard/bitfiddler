#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>


void client(char *message, char *server_ip, int server_port);


int main() {
    client("Hello World!", "127.0.0.1", 8080);
    client("Just for test multiple messages.", "127.0.0.1", 8080);

    return 0;
}


void client(char *message, char *server_ip, int server_port) {
    /*
    The client side used to send requests to the server.

    Arguments:
        message(char*): The data will be sent to the server.
        server_ip(char*): The IP of the server(e.g., 127.0.0.1) to connect to it.
        server_port(int): The port number of the server to connect to.

    NOTE:
        htons: make sure the port number is stored in the correct byte order for network communication.
        inet_pton: converts a human-readable IP address(127.0.0.1) to a binary format that sockets need.
            So, string IP becomes packet network format.
    */

    int sockfd = 0;
    char buffer[1024] = {0};

    // A structure to hold the server info
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // Check the socket creation status(failed or successful)
    if(sockfd < 0) {
        perror("socket creation failed\n");
        exit(1);
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);

    // Convert IP to binary and set it
    if(inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("invalid server address\n");
        exit(1);
    }

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection to the server failed\n");
        exit(1);
    }

    // Send message
    ssize_t bytes_sent = send(sockfd, message, strlen(message), 0);
    if(bytes_sent < 0) {
        perror("failed to send data to the server\n");
        exit(1);
    }

    // Receive response from the server and print the buffer data
    ssize_t bytes_read = read(sockfd, buffer, sizeof(buffer)-1);
    if(bytes_read < 0) {
        perror("receiving data from the server failed\n");
        exit(1);
    }

    // Ensure null-terminated
    buffer[bytes_read] = '\0';

    printf("Server Respond: %s\n", buffer);

    // Close the connection
    close(sockfd);
}
