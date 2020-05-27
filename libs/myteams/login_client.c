/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** login_client
*/
#include "../include/client.h"

void send_mp(char **tab, t_client *c)
{
    (void)c;
    client_event_private_message_received(tab[1], tab[2]);
}

void print_user(char **tab, t_client *c)
{
    (void)c;
    client_print_user(tab[1], tab[2], atoi(tab[3]));
}

void print_users(char **tab, t_client *c)
{
    (void)c;
    client_print_users(tab[1], tab[2], atoi(tab[3]));
}

void login_cli(char **tab, t_client *c)
{
    (void)c;
    client_event_loggedin(tab[1], tab[2]);
}

void logout_cli(char **tab, t_client *c)
{
    client_event_loggedout(tab[1], tab[2]);
    if (c->is_connect == 1)
        exit(0);
}