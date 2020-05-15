/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** logout
*/

#include "../../include/serveur.h"

void logout(char **tab, client_t *client, server_t *srv)
{
    (void)tab;
    if (client->is_login != 0) {
        server_event_user_logged_out(client->uuid);
        for (int i = 0; i < 1000; i += 1) {
            (srv->cli[i].uuid != client->uuid) ? dprintf(srv->cli[i].fd,
            "502 %s %s\n", client->uuid, client->username) : 0;
        }
        memset(client->username, 0, 32);
        memset(client->uuid, 0, 37);
        client->is_login = 0;
        return;
    }
}