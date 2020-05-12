/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init
*/

#include "include/client.h"

void errorHandling(char *str)
{
    perror(str);
    exit (84);
}

int initClient(t_client *c)
{
    int sock = 0;
    char buff[1024];
    struct sockaddr_in serv_addr;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        errorHandling("Init Socket Error");
    memset(buff, '0', sizeof(buff));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(c->port);
    if (inet_pton(AF_INET, c->ip, &serv_addr.sin_addr) < 1)
        errorHandling("IP Error");
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        errorHandling("Connection Error");
    readFromClient(c, sock, buff);
    return (0);
}

int readFromClient(t_client *c, int fd, char *buff)
{
    int readNb = 0;
    while (readNb = read(fd, buff, sizeof(buff) - 1) > 0) {
        buff[readNb] = '\0';
        if (fputs(buff, stdout) == EOF)
            errorHandling("Fputs error");
    }
    if (readNb < 0)
        errorHandling("Read error");
    return (0);
}

int loop(t_client *c)
{
    char *input = NULL;
    while (12)
    {

    }
    return (0);
}