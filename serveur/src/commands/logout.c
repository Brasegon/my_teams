/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** logout
*/

#include "../../include/serveur.h"

void logout(char **tab, client_t *client)
{
    if (client->is_login != 0) {
        server_event_user_logged_out(client->uuid);
        memset(client->username, 0, 32);
        memset(client->uuid, 0, 37);
        client->is_login = 0;
        return;
    }
}