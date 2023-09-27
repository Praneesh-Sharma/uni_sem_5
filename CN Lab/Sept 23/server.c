#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

int main() {
    int server_fd, new_socket, max_fd, activity;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int client_sockets[MAX_CLIENTS];
    char message[MAX_MSG_LEN];

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345); // Change port as needed

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Initialize client sockets
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    printf("Server is running. Waiting for connections...\n");

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        max_fd = server_fd;

        // Add client sockets to the set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];
            if (sd > 0) {
                FD_SET(sd, &read_fds);
                if (sd > max_fd) {
                    max_fd = sd;
                }
            }
        }

        // Wait for activity on any socket
        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Select error");
            exit(EXIT_FAILURE);
        }

        // Check for incoming connections
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // Add new socket to the array of client sockets
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    printf("New connection, socket fd is %d, IP is: %s, port is: %d\n", new_socket, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                    break;
                }
            }
        }

        // Handle client messages
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];
            if (FD_ISSET(sd, &read_fds)) {
                memset(message, 0, sizeof(message));
                int valread = read(sd, message, sizeof(message));

                if (valread == 0) {
                    // Client disconnected
                    printf("Client %d disconnected\n", sd);
                    close(sd);
                    client_sockets[i] = 0;
                } else {
                    // Process the received message
                    printf("Client %d: %s", sd, message);

                    // Check for "exit" message to terminate the connection
                    if (strcmp(message, "exit\n") == 0) {
                        printf("Client %d requested to exit\n", sd);
                        close(sd);
                        client_sockets[i] = 0;
                    }
                }
            }
        }
    }

    return 0;
}
