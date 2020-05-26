/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** login
*/
#include "../../include/serveur.h"

int check_user_connect(char *user, server_t *srv, client_t *c)
{
    for (int i = 0; i < 1000; i += 1) {
        if (strcmp(user, srv->cli[i].username) == 0) {
            srv->queue = srv->queue->push_front
            (srv->queue, "102\n", c->fd);
            return (1);
        }
    }
    return (0);
}

void connect_login(char **tab, client_t *client)
{
    strcpy(client->username, tab[0]);
    strcpy(client->uuid, tab[1]);
    client->is_login = 1;
    client->use_mode = 0;
    server_event_user_logged_in(client->uuid);
}

void create_new_login(char *user, client_t *client)
{
    uuid_t binuuid;

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, client->uuid);
    client->is_login = 1;
    client->use_mode = 0;
    strcpy(client->username, user);
    server_event_user_created(client->uuid, client->username);
    server_event_user_logged_in(client->uuid);
}

void check_user_exist(char *user, client_t *client, server_t *srv)
{
    char line[256];
    char **tab;
    FILE *login = fopen("save/login.txt", "a+");
    memset(line, 0, 256);
    while (fgets(line, sizeof(line), login) != NULL) {
        tab = my_str_to_word_array(line);
        if (strcmp(tab[0], user) == 0) {
            connect_login(tab, client);
            sprintf(line, "501 %s %s\n", client->uuid, client->username);
            srv->queue = srv->queue->push_back(srv->queue, line, client->fd);
            fclose(login);
            return;
        }
    }
    create_new_login(user, client);
    sprintf(line, "501 %s %s\n", client->uuid, client->username);
    srv->queue = srv->queue->push_back(srv->queue, line, client->fd);
    fprintf(login, "%s %s\n", client->username, client->uuid);
    fclose(login);
}

void login(char **tab, client_t *client, server_t *srv)
{
    char line[256];
    if (client->is_login == 0) {
        if (count_tab(tab) < 2) {
            srv->queue = srv->queue->push_front
            (srv->queue, "101\n", client->fd);
            return;
        }
        if (check_user_connect(tab[1], srv, client) == 1)
            return;
        check_user_exist(tab[1], client, srv);
        for (int i = 0; i < 1000; i += 1) {
            (srv->cli[i].uuid != client->uuid &&
            srv->cli[i].fd != -1) ? sprintf(line,
            "501 %s %s\n", client->uuid, client->username) : 0;
            srv->queue = (srv->cli[i].uuid != client->uuid &&
            srv->cli[i].fd != -1) ?
            srv->queue->push_back(srv->queue, line, srv->cli[i].fd) :
            srv->queue;
        }
    }
}