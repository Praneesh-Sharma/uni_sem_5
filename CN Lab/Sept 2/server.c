#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 2

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    pid_t childpid;
    int client_sockets[MAX_CLIENTS] = {0};
    int num_clients = 0;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if (num_clients < MAX_CLIENTS) {
            client_sockets[num_clients] = new_socket;
            num_clients++;
            if ((childpid = fork()) == 0) {
                close(server_fd);
                while (1) {
                    valread = read(new_socket, buffer, 1024);
                    if (valread == 0) {
                        printf("Client disconnected\n");
                        break;
                    }
                    printf("Client: %s\n", buffer);
                    if (strcmp(buffer, "exit") == 0) {
                        printf("Terminating connection with client\n");
                        break;
                    }
                    send(new_socket, hello, strlen(hello), 0);
                    memset(buffer, 0, sizeof(buffer));
                }
                close(new_socket);
                exit(0);
            }
        } else {
            printf("Max number of clients reached\n");
            close(new_socket);
        }
    }
    return 0;
}

