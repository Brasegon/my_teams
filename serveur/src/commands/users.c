/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** users
*/

#include "../../include/serveur.h"

void users(char **tab, client_t *client, server_t *srv)
{
    FILE *login = fopen("save/login.txt", "a+");
    char line[1024];
    int connect = 0;
    memset(line, 0, 1024);
    printf("Je passe par la\n");
    while (fgets(line, sizeof(line), login) != NULL) {
        tab = my_str_to_word_array(line);
        sprintf(line, "505 %s %s %d\n",
        tab[1], tab[0], connect);
        srv->queue = srv->queue->push_back(srv->queue, line, client->fd);
    }
}