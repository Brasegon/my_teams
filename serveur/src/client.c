/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** client
*/

#include "../include/serveur.h"

t_list *send_queue(t_list *list)
{
    t_list *tmp = list;
    int i = 0;
    
    while (tmp) {
        if (strcmp(tmp->msg, "**BEGIN**") == 0) {
            tmp = tmp->next;
        } else {
            dprintf(tmp->fd, "%s", tmp->msg);
            tmp = tmp->next;
        }
    }
    return (list);
}

void create_client(server_t *srv)
{
    for (int i = 0; i < 1000; i += 1) {
        if (srv->cli[i].fd == -1) {
            socklen_t size = sizeof(srv->clientaddr);
            srv->cli[i].fd = accept(srv->sock_fd_s,
                (struct sockaddr *) &srv->clientaddr, &size);
            srv->cli[i].ip = inet_ntoa(srv->clientaddr.sin_addr);
            FD_SET(srv->cli[i].fd, &srv->active_fd_set);
            break;
        }
    }
}

void client_connection(server_t *server, int i)
{
    if (FD_ISSET(i, &server->read_fd_set)) {
        if (i == server->sock_fd_s) {
            create_client(server);
        } else {
            check_commands(server, i);
        }
    }
}