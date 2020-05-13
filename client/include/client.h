/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <time.h> 

typedef struct s_client
{
    char *ip;
    short port;
    int socketFd;
}t_client;

typedef struct s_commands
{
    char *command;
}t_commands;

// init.c
void errorHandling(char *str);
int initClient(t_client *c);
int readFromServer(t_client *c, int fd, char *buff);

//input.c
int loop(t_client *c);
char *prompt(void);

#endif /* !CLIENT_H_ */
