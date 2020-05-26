/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** commands
*/
#include "../include/serveur.h"
#include <ctype.h>

const command_t commands[] = {
    {"/login", &login},
    {"/logout", &logout},
    {"/create", &create},
    {"/send", &send_mp},
    {"/use", &use},
    {"/users", &users},
    {"/user", &user},
    {NULL, NULL}
};

void launch_command(char **tab, server_t *srv, int z)
{
    if (count_tab(tab) < 1) {
        dprintf(srv->cli[z].fd, "404 Command not found\n");
    }
    for (int i = 0; commands[i].name != NULL; i += 1) {
        if (strcmp(tab[0], commands[i].name) == 0) {
            (commands[i].func)(tab, &srv->cli[z], srv);
            return;
        }
    }
    dprintf(srv->cli[z].fd, "404 Command not found\n");
}

void check_quit(int i, server_t *srv, int z, char *buffer)
{
    char **tab = NULL;

    if (i < 1) {
        printf("Déconnection d'un client\n");
        close(srv->cli[z].fd);
        FD_CLR(srv->cli[z].fd, &srv->active_fd_set);
        srv->cli[z].fd = -1;
        memset(srv->cli[z].username, 0, 32);

    } else {
        tab = my_str_to_word_array(buffer);
        launch_command(tab, srv, z);
        free(tab);
        memset(buffer, 0, 1024);
    }
}

void check_commands(server_t *srv, int fd_cli)
{
    char buffer[1024];
    memset(buffer, 0, 1024);
    int i = recv(fd_cli, buffer, 1024, 0);
    for (int z = 0; z < 1000; z += 1) {
        if (fd_cli == srv->cli[z].fd) {
            check_quit(i, srv, z, buffer);
            break;
        }
    }
}