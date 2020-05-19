/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** create_teams
*/
#include "../../include/serveur.h"

void create_teams(char **tab, client_t *client, server_t *srv)
{
    FILE *teams = fopen("save/teams.txt", "a+");
    uuid_t binuuid;
    char uuid[37];
    char str[1024];
    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    fprintf(teams, "%s %s \"%s\"\n", uuid, tab[1], tab[2]);
    sprintf(str, "520 %s %s \"%s\"\n", uuid, tab[1], tab[2]);
    srv->queue = srv->queue->push_front(srv->queue, str, client->fd);
    server_event_team_created(uuid, tab[1], client->uuid);
    fclose(teams);
}