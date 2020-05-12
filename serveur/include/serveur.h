/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
typedef struct server_s {
    int port;
    int sock_fd_s;
    socklen_t sock_len;
    struct protoent *proto;
    struct sockaddr_in  s_in;
} server_t;

void serveur(int port);
#endif /* !CLIENT_H_ */
