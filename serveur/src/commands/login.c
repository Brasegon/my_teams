/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** login
*/
#include "../../include/serveur.h"

void connect_login(char **tab, client_t *client)
{
    strcpy(client->username, tab[0]);
    strcpy(client->uuid, tab[1]);
    client->is_login = 1;
    server_event_user_logged_in(client->uuid);
}

void create_new_login(char *user, client_t *client)
{
    uuid_t binuuid;

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, client->uuid);
    client->is_login = 1;
    strcpy(client->username, user);
    server_event_user_created(client->uuid, client->username);
    server_event_user_logged_in(client->uuid);
}

void check_user_exist(char *user, client_t *client)
{
    char line[256];
    char **tab;
    FILE *login = fopen("save/login.txt", "a+");

    memset(line, 0, 256);
    while (fgets(line, sizeof(line), login) != NULL) {
        tab = my_str_to_word_array(line);
        if (strcmp(tab[0], user) == 0) {
            connect_login(tab, client);
            // send(client->fd, line, 256, 0);
            fclose(login);
            return;
        }
    }
    create_new_login(user, client);
    fprintf(login, "%s %s\n", client->username, client->uuid);
    fclose(login);
}

void login(char **tab, client_t *client)
{
    if (client->is_login == 0) {
        if (count_tab(tab) < 2) {
            dprintf(client->fd, "100 Please enter a name\n");
            return;
        }
        check_user_exist(tab[1], client);
        return;
    }
    dprintf(client->fd, "101 You are already connected\n");
}