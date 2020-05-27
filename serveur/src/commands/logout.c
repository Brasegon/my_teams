/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** logout
*/

#include "../../include/serveur.h"

void logout(char **tab, client_t *client, server_t *srv)
{
    char line[256];
    (void)tab;
    if (client->is_login != 0) {
        server_event_user_logged_out(client->uuid);
        for (int i = 0; i < 1000; i += 1) {
            sprintf(line,
            "502 %s \"%s\"\n", client->uuid, client->username);
            srv->queue = (srv->cli[i].fd != -1) ?
            srv->queue->push_back(srv->queue, line, srv->cli[i].fd):
            srv->queue;
        }
        memset(client->username, 0, 32);
        memset(client->uuid, 0, 37);
        client->is_login = 0;
        return;
    }
    srv->queue = srv->queue->push_front(srv->queue, "101\n", client->fd);
}