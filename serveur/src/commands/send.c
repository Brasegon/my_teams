/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** send
*/

#include "../../include/serveur.h"

void send_mp(char **tab, client_t *client, server_t *srv)
{
    char line[1024];
    if (client->is_login != 1) {
        srv->queue = srv->queue->push_front(srv->queue, "101\n", client->fd);
        return;
    }
    printf("%s\n", tab[1]);
    for (int i = 0; i < 1000; i += 1) {
        if (strcmp(tab[1], srv->cli[i].uuid) == 0) {
            sprintf(line, "507 %s \"%s\"\n", client->uuid, tab[2]);
            srv->queue = srv->queue->push_back(srv->queue, line,
            srv->cli[i].fd);
            srv->queue = srv->queue->push_back(srv->queue, "1\n",
            client->fd);
            server_event_private_message_sended
            (client->uuid, srv->cli[i].uuid, tab[2]);
            return;
        }
    }
    sprintf(line, "607 %s\n", tab[1]);
    srv->queue = srv->queue->push_back(srv->queue, line,
    client->fd);
}