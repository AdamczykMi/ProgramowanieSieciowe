#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        perror("Incorrect number of arguments was entered");
        return -1;
    }

    int sock;
    ssize_t cnt;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr = {
            .sin_family = AF_INET,
            .sin_addr = { .s_addr = inet_addr(argv[1]) },
            .sin_port = htons(atoi(argv[2]))
    };

    unsigned char empty_buff[1];

    cnt = sendto(sock, empty_buff, sizeof(empty_buff) - 1, 0, (struct sockaddr *) &addr, sizeof(addr));
    if (cnt == -1) {
        perror("sendto");
        return 1;
    }

    printf("Sent: %s\n", empty_buff);

    char buff[1024];

    cnt = recvfrom(sock, buff, sizeof(buff) - 1, 0, NULL, NULL);
    if (cnt == -1) {
        perror("recvfrom");
        return 1;
    }

    printf("Received: %s\n", buff);

    close(sock);

    return 0;
}