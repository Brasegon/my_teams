/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** create
*/
#include "../../include/serveur.h"

void create(char **tab, client_t *client, server_t *srv)
{
    if (client->is_login != 0) {
        if (count_tab(tab) < 3)
            return;
        if (client->use_mode == 0) {
            create_teams(tab, client, srv);
        }
        if (client->use_mode == 1) {
            create_channels(tab, client, srv);
        }
    }
}