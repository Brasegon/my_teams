/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** input
*/

#include "include/client.h"

void socketHandler(t_client *c, fd_set read, fd_set write)
{
    if (select(4, &read, &write, NULL, NULL) != -1) {
        if (FD_ISSET(0, &read)) {
            input = prompt();
        } if (FD_ISSET(c->socketFd, &read)) {
            recv(c->socketFd, buff, 256, 0);
            printf("%s\n", buff);
            memset(buff, 0, 256);
        } if (FD_ISSET(c->socketFd, &write)) {
            if (input != NULL) {
                send(c->socketFd, input, 256, 0);
            }
        }
    }
}

int loop(t_client *c)
{
    char *input = NULL;
    char buff[1024] = {0};
    fd_set read;
    fd_set write;
    while (12) {
        FD_ZERO(&read);
        FD_ZERO(&write);
        FD_SET(0, &read);
        FD_SET(1, &write);
        FD_SET(c->socketFd, &read);
        FD_SET(c->socketFd, &write);
        socketHandler(c, read, write);
        if (input)
            input = NULL;
    }
    free(input);
    return (0);
}

char *prompt(void)
{
    char *line = malloc(sizeof(char) * 1024);
    if (line == NULL)
        errorHandling("Error Malloc Prompt");
    fgets(line, strlen(line), stdin);
    return (line);
}