/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** commands
*/
#include "../include/serveur.h"
#include "../include/logging_server.h"

void check_quit(int i, server_t *srv, int z)
{
    if (i < 1) {
        printf("Déconnection d'un client\n");
        close(srv->cli[z].fd);
        FD_CLR(srv->cli[z].fd, &srv->active_fd_set);
        srv->cli[z].fd = -1;
    }
}

void check_commands(server_t *srv, int fd_cli)
{
    char buffer[256];
    int i = recv(fd_cli, buffer, 256, 0);
    for (int z = 0; z < 1000; z += 1) {
        if (fd_cli == srv->cli[z].fd) {
            check_quit(i, srv, z);
        }
    }
}