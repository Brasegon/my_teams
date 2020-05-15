/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** send
*/

#include "../../include/serveur.h"

void send_mp(char **tab, client_t *client, server_t *srv)
{
    if (client->is_login != 1)
        return;
    for (int i = 0; i < 1000; i += 1) {
        if (strcmp(tab[1], srv->cli[i].uuid) == 0) {
            dprintf(srv->cli[i].fd, "507 %s \"%s\"\n", tab[1], tab[2]);
            return;
        }
    }
}