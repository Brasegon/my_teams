/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** create
*/

#include "../include/client.h"

void create_teams(char **tab, t_client *c)
{
    (void)c;
    client_print_team_created(tab[1], tab[2], tab[3]);
    client_event_team_created(tab[1], tab[2], tab[3]);
}

void create_channel(char **tab, t_client *c)
{
    (void)c;
    client_print_channel_created(tab[1], tab[2], tab[3]);
    client_print_channel_created(tab[1], tab[2], tab[3]);
}
