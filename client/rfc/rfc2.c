/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** rfc2
*/

#include "../include/client.h"

void create_teams(char **tab, t_client *c)
{
    client_event_team_created(tab[1], tab[2], tab[3]);
}