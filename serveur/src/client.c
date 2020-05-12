/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** client
*/

#include "../include/serveur.h"

void create_client(int socket, server_t *srv)
{
    socklen_t size = sizeof(srv->clientaddr);
    srv->cli[srv->number_cli].fd = accept(srv->sock_fd_s,
        (struct sockaddr *) &srv->clientaddr, &size);
    srv->cli[srv->number_cli].ip = inet_ntoa(srv->clientaddr.sin_addr);
    printf("Server: connect from host %s\n", srv->cli[srv->number_cli].ip);
    FD_SET(srv->cli[srv->number_cli].fd, &srv->active_fd_set);
    srv->number_cli += 1;
}

void client_connection(server_t *server, int i)
{
    int z = 0;
    if (FD_ISSET(i, &server->read_fd_set)) {
        if (i == server->sock_fd_s) {
            create_client(server->sock_fd_s, server);
        }
    }
}