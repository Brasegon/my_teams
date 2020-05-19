/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** users
*/

#include "../../include/serveur.h"

int check_if_online(char **tab, server_t *srv)
{
    for (int i = 0; i < 1000; i += 1) {
        if (strcmp(tab[1], srv->cli[i].uuid) == 0) {
            return (1);
        }
    }
    return (0);
}

void user(char **tab, client_t *client, server_t *srv)
{
    FILE *login = fopen("save/login.txt", "a+");
    char line[1024];
    int connect = 0;
    char **user;
    memset(line, 0, 1024);
    if (client->is_login == 0)
        return;
    while (fgets(line, sizeof(line), login) != NULL) {
        user = my_str_to_word_array(line);
        connect = check_if_online(tab, srv);
        if (strcmp(tab[1], user[1]) == 0) {
            sprintf(line, "505 %s %s %d\n",
            user[1], user[0], connect);
            srv->queue = srv->queue->push_back(srv->queue, line, client->fd);
            return;
        }
    }
}

void users(char **tab, client_t *client, server_t *srv)
{
    FILE *login = fopen("save/login.txt", "a+");
    char line[1024];
    int connect = 0;
    memset(line, 0, 1024);
    if (client->is_login == 0)
        return;
    while (fgets(line, sizeof(line), login) != NULL) {
        tab = my_str_to_word_array(line);
        connect = check_if_online(tab, srv);
        sprintf(line, "505 %s %s %d\n",
        tab[1], tab[0], connect);
        srv->queue = srv->queue->push_back(srv->queue, line, client->fd);
    }
}