/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** create_teams
*/
#include "../../include/serveur.h"

void create_teams(char **tab, client_t *client)
{
    FILE *teams = fopen("save/teams.txt", "a+");
    uuid_t binuuid;
    char uuid[37];

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    int i = fprintf(teams, "%s %s %s\n", uuid, tab[1], tab[2]);
    printf("%d\n", i);
}