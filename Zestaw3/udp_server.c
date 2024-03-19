#define _POSIX_C_SOURCE 200809L
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main()
{
    int sock;
    ssize_t cnt;

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket error");
        exit(1);
    }


    struct sockaddr_in addr = {
            .sin_family = AF_INET,
            .sin_addr = {.s_addr = htonl(INADDR_ANY) },
            .sin_port = htons(2020)
    };

    if ((bind(sock, (struct sockaddr*)&addr, sizeof(addr))) == -1) {
        perror("socket bind error");
        exit(1);
    }


    while (1) {

        int i = 0;
        int j = 0;
        char buf[60000];
        char num[100];
        long int sum = 0;
        char operator = '+';
        bool error = false;
        errno = 0;

        struct sockaddr_in clnt_addr;
        socklen_t clnt_addr_len;
        clnt_addr_len = sizeof(clnt_addr);

        cnt = recvfrom(sock, buf, sizeof(buf), 0,
                       (struct sockaddr*)&clnt_addr, &clnt_addr_len);
        if (cnt == -1) {
            perror("recvfrom");
            exit(1);
        }


        while (i < cnt+1) {

            if(buf[0]==10){
                error = true;
                break;
            }
            if (buf[i] >= '0' && buf[i] <= '9') {
                num[j] = buf[i];
            }
            else if ((buf[i] == '-' || buf[i] == '+')&&i!=0
                     &&buf[i+1]!='\0'
                     &&buf[i+1]!='\n'
                     &&buf[i+1]!='\r'
                     &&buf[i+1]!='-'
                     &&buf[i+1]!='+' ){
                num[j] = '\0';
                int tempConvert = strtol(num, NULL, 10);
                if (errno != 0) {
                    error = true;
                    break;
                }
                if (operator=='+') {
                    sum += tempConvert;
                }
                else {
                    sum -= tempConvert;
                }
                operator = buf[i];
                j = -1; // przeskok do j==0 w nastepnym kroku
            }
            else  if (buf[i] == '\0' || buf[i] == '\n' || buf[i] == '\r') {
                num[j] = '\0';
                int tempConvert = strtol(num, NULL, 10);
                if (errno != 0) {
                    error = true;
                    break;
                }
                if (operator=='+') {
                    sum += tempConvert;
                }
                else {
                    sum -= tempConvert;
                }
                break;
            }
            else {
                error = true;
                break;
            }
            i++;
            j++;
        }
        char out[20];
        sprintf(out,"%ld",sum);
        strcat(out,"\n");
        if (error == true) {
            cnt = sendto(sock, "ERROR\n", 6, 0,
                         (struct sockaddr*)&clnt_addr, clnt_addr_len);
        }
        else {
            cnt = sendto(sock, out, strlen(out), 0,
                         (struct sockaddr*)&clnt_addr, clnt_addr_len);
        }
        if (cnt == -1) {
            perror("sendto error");
            exit(1);
        }

    }

    if ((close(sock)) == -1) {
        perror("error closing socket");
        exit(1);
    }

    return 0;
}
