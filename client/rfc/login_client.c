/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** login_client
*/
#include "../include/client.h"

void login_cli(char **tab, t_client *c)
{
    client_event_loggedin(tab[1], tab[2]);
}

void logout_cli(char **tab, t_client *c)
{
    client_event_loggedout(tab[1], tab[2]);
}