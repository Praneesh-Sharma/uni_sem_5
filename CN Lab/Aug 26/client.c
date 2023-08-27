#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    int client_socket;
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation error");
        exit(1);
    }

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection error");
        exit(1);
    }

    printf("Connected to server at %s:%d\n", server_ip, server_port);

    char message[1024];
    while (1) {
        printf("Enter message (or 'exit' to close): ");
        fgets(message, sizeof(message), stdin);
        message[strlen(message) - 1] = '\0'; // Remove newline

        send(client_socket, message, strlen(message), 0);

        if (strcmp(message, "exit") == 0) {
            break;
        }
    }

    printf("Connection closed.\n");
    close(client_socket);

    return 0;
}
