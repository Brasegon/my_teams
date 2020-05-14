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
#include <sys/select.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <uuid/uuid.h>
#include "logging_server.h"


typedef struct client_s {
    char *ip;
    int fd;
    int use_mode;
    char uuid[37];
    char username[32];
    int is_login;
    struct client_s *next;
} client_t;


typedef struct server_s {
    int port;
    int sock_fd_s;
    int number_cli;
    struct sockaddr_in clientaddr;
    socklen_t sock_len;
    struct protoent *proto;
    struct sockaddr_in  s_in;
    fd_set active_fd_set;
    fd_set read_fd_set;
    client_t cli[1000];
} server_t;

typedef struct command
{
    char *name;
    void (*func)(char **tab, client_t *clt, server_t *srv);
} command_t;
extern const command_t commands[];

void serveur(int port);
void create_client(server_t *srv);
void client_connection(server_t *server, int i);
char **my_str_to_word_array(char const *str);
void check_commands(server_t *srv, int fd_cli);
int count_tab(char **tab);

void login(char **tab, client_t *clt, server_t *srv);
void logout(char **tab, client_t *client, server_t *srv);
void create(char **tab, client_t *client, server_t *srv);
void create_teams(char **tab, client_t *client);
void send_mp(char **tab, client_t *client, server_t *srv);
#endif /* !CLIENT_H_ */
