/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** create_channel
*/
#include "../../include/serveur.h"

void create_channels(char **tab, client_t *client, server_t *srv)
{
    FILE *channel = fopen("save/channels.txt", "a+");
    uuid_t binuuid;
    char uuid[37];
    char str[1024];
    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    fprintf(channel, "%s %s %s \"%s\"\n",
    client->teams_uuid, uuid, tab[1], tab[2]);
    sprintf(str, "521 %s %s \"%s\"\n", uuid, tab[1], tab[2]);
    srv->queue = srv->queue->push_front(srv->queue, str, client->fd);
    server_event_channel_created(client->teams_uuid, uuid, tab[1]);
    fclose(channel);
}