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
    char buff[1024];
    struct sockaddr_in serv_addr;
    c->socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (c->socketFd < 0)
        errorHandling("Init Socket Error");
    memset(buff, '0', sizeof(buff));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(c->port);
    if (inet_pton(AF_INET, c->ip, &serv_addr.sin_addr) < 1)
        errorHandling("IP Error");
    if (connect(c->socketFd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        errorHandling("Connection Error");
    readFromServer(c, c->socketFd, buff);
    return (0);
}

int readFromServer(t_client *c, int fd, char *buff)
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