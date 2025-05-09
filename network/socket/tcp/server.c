#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>


void server(char *response, int server_port);


int main() {
    server("Hello Client...", 8080);

    return 0;
}


void server(char *response, int server_port) {
    /*
    Handles the server-side logic for receiving client requests and sending responses.

    Arguments:
        response(char*): The response message sent back to the client upon a successful connection.
        server_port(int): The port number the server will bind to.

    NOTE:
        htons: make sure the port number is stored in the correct byte order for network communication.
    */

    int server_fd, client_fd;
    char buffer[1024] = {0};

    struct sockaddr_in server_addr, client_addr;
    // Get the size of client address
    socklen_t addr_len = sizeof(client_addr);

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) {
        perror("socket creation failed\n");
        exit(1);
    }

    // Binding IP/Port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);

    if( bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 ) {
        perror("binding operation failed\n");
        exit(1);
    }

    // Listen for connections with 9 backlog
    listen(server_fd, 9);
    printf("Server is listening on port \"%d\"...\n", server_port);

    // Accept client connection
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
    if(client_fd < 0) {
        perror("accept failed\n");
        exit(1);
    }

    // Read data from client
    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer)-1);
    if(bytes_read < 0) {
        perror("receiving data from the client failed\n");
        exit(1);
    }
    // Ensure null-terminated
    buffer[bytes_read] = '\0';

    printf("Client Data: %s\n", buffer);

    // Send response to the client
    ssize_t bytes_send = send(client_fd, response, strlen(response), 0);
    if(bytes_send < 0) {
        perror("sending data to the client failed\n");
        exit(0);
    }

    // Close the connections
    close(server_fd);
    close(client_fd);
}
