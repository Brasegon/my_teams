/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** create_channel
*/
#include "../../include/serveur.h"

void create_channels(char **tab, client_t *client)
{
    FILE *channel = fopen("save/channels.txt", "a+");
    uuid_t binuuid;
    char uuid[37];

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    fprintf(channel, "%s %s %s \"%s\"\n",
    client->teams_uuid, uuid, tab[1], tab[2]);
    server_event_channel_created(client->teams_uuid, uuid, tab[1]);
    fclose(channel);
}