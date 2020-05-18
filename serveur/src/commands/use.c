/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** use
*/
#include "../../include/serveur.h"

void use_teams(char **tab, client_t *client)
{
    FILE *teams = fopen("save/teams.txt", "a+");
    char line[256];
    char **file;
    if (tab[1] == NULL) {
        client->use_mode = 0;
        return;
    }
    while (fgets(line, sizeof(line), teams) != NULL) {
        file = my_str_to_word_array(line);
        if (strcmp(tab[1], file[0]) == 0) {
            client->use_mode = 1;
            strcpy(client->teams_uuid, file[0]);
            dprintf(client->fd, "503 Ok\n");
            return;
        }
    }
    dprintf(client->fd, "603 Not found\n");
    fclose(teams);
}

void use(char **tab, client_t *client, server_t *srv)
{
    if (client->is_login != 0) {
        (void) srv;
        use_teams(tab, client);
        return;
    }
    dprintf(client->fd, "100 Please loggin in\n");
}