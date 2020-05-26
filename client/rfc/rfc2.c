/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** rfc2
*/

#include "../include/client.h"

void error_already(char **tab, t_client *c)
{
    (void)tab;
    (void)c;
    client_error_already_exist();
}

void create_teams(char **tab, t_client *c)
{
    (void)c;
    client_event_team_created(tab[1], tab[2], tab[3]);
}

void error_command(char **tab, t_client *c)
{
    (void)tab;
    (void)c;
    client_error_unauthorized();
}

void error_user(char **tab, t_client *c)
{
    (void)c;
    client_error_unknown_user(tab[1]);
}

void error_use(char **tab, t_client *c)
{
    (void)c;
    if (strcmp(tab[1], "team") == 0) {
        client_error_unknown_team(tab[2]);
    } else if (strcmp(tab[1], "channel") == 0) {
        client_error_unknown_channel(tab[2]);
    }
}