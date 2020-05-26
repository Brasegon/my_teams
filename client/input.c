/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** input
*/

#include "include/client.h"

const t_rfc rfc[] = {
    {"501", &login_cli},
    {"502", &logout_cli},
    {"505", &print_users},
    {"506", &print_user},
    {"507", &send_mp},
    {"603", &error_use},
    {"520", &create_teams},
    {"101", &error_command},
    {"607", &error_user},
    {NULL, NULL}
};

void check_logout(char *input)
{
    char **tab = my_str_to_word_array(input);

    if (strcmp(tab[0], "/logout") == 0)
        exit(0);
}

void check_commands(t_client *c)
{
    char **tab = my_str_to_word_array(c->buff);

    if (count_tab(tab) < 1)
        return;
    for (int i = 0; rfc[i].name != NULL; i += 1) {
        if (strcmp(tab[0], rfc[i].name) == 0) {
            (rfc[i].func)(tab, c);
            return;
        }
    }
}

void socketHandler(t_client *c, fd_set read, fd_set write)
{
    if (select(4, &read, &write, NULL, NULL) != -1) {
        if (FD_ISSET(0, &read)) {
            c->input = prompt();
        } if (FD_ISSET(c->socketFd, &read)) {
            recv(c->socketFd, c->buff, 1024, 0);
            check_commands(c);
            memset(c->buff, 0, 1024);
        } if (FD_ISSET(c->socketFd, &write)) {
            if (c->input != NULL) {
                send(c->socketFd, c->input, 1024, 0);
                check_logout(c->input);
            }
        }
    }
    if (c->input) {
        c->input = NULL;
    } if (!c->input)
        free(c->input);
}

int loop(t_client *c)
{
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
    }
    return (0);
}

char *prompt(void)
{
    char *line = malloc(sizeof(char) * 1024);
    int i = read(0, line, 1024);
    if (i == 0)
        line = strcpy(line, "/logout");
    if (i == 1)
        return (NULL);
    return (line);
}