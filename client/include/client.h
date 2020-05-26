/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** client
*/

#ifndef  READ_SIZE
#define  READ_SIZE (1)
#endif  /* !READ_SIZE  */

#ifndef CLIENT_H_
#define CLIENT_H_

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
#include <sys/select.h>
#include "../../common/list.h"
#include "logging_client.h"

typedef struct s_client
{
    char *ip;
    short port;
    int socketFd;
    int fd;
    char buff[1024];
    char *input;
} t_client;

typedef struct s_rfc
{
    char *name;
    void (*func)(char **tab, t_client *c);
}t_rfc;
typedef struct s_commands
{
    char *command;
    void (*func)(char **tab, int fd);
}t_commands;

extern const t_commands commands[];
extern const t_rfc rfc[];

// init.c
void errorHandling(char *str);
int initClient(t_client *c);
int readFromServer(t_client *c, int fd, char *buff);

// commands.c
void sendMessage(int fd, char *message);
int countTab(char **tab);
void launchCommand(char **tab, t_client *c);
void check_commands(t_client *c);

// input.c
void socketHandler(t_client *c, fd_set read, fd_set write);
int loop(t_client *c);
char *prompt(void);

//Commands List

//log.c (Contient /login et /logout)
void login(char **tab, int fd); // Login
void logout(char **tab, int fd); // Logout

//help.c (Contient /help)

// rfc
void login_cli(char **tab, t_client *c);
void logout_cli(char **tab, t_client *c);
void print_users(char **tab, t_client *c);
void print_user(char **tab, t_client *c);
void send_mp(char **tab, t_client *c);
void create_teams(char **tab, t_client *c);
void error_command(char **tab, t_client *c);
void error_use(char **tab, t_client *c);
void error_user(char **tab, t_client *c);
void error_already(char **tab, t_client *c);
#endif /* !CLIENT_H_ */
