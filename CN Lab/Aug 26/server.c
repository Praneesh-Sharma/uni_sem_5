/*Write a connection-oriented client and server program in C using
command line arguments. At the server side, pass the port number (to
whom the server will bind to) in the command line. At the client side, pass
the IP address and the port number of the server (to whom the client will
connect to) as command line argument and carry out the following tasks.
i. Print all the relevant messages during the connection establishment at
both the ends.
ii. After establishment of connection exchange messages. After message
exchange is over then the client sends a “close” message to the server
to tear down the connection.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation error");
        exit(1);
    }

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding error");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("Listening error");
        exit(1);
    }

    printf("Server listening on port %d...\n", port);

    addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
    if (client_socket == -1) {
        perror("Accepting error");
        exit(1);
    }

    printf("Connection established with client.\n");

    char buffer[1024];
    while (1) {
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message from client: %s\n", buffer);
    }

    printf("Connection closed by client.\n");
    close(client_socket);
    close(server_socket);

    return 0;
}
