#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_MSG_LEN 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char message[MAX_MSG_LEN];

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345); // Change to match the server port
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to the server's IP address

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server. Type 'exit' to quit.\n");

    while (1) {
        memset(message, 0, sizeof(message));
        printf("Enter a message: ");
        fgets(message, sizeof(message), stdin);

        // Send the message to the server
        send(client_socket, message, strlen(message), 0);

        if (strcmp(message, "exit\n") == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    close(client_socket);
    return 0;
}
