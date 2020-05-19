/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** commands
*/

#include "include/client.h"
// #include "include/commands.h"

const t_commands commands[] =
{
    {"/login", &login},
    {"/logout", &logout},
    {NULL, NULL}
};

void sendMessage(int fd, char *message)
{
    dprintf(fd, "%s", message);
}

int countTab(char **tab)
{
    int i = 0;
    while (tab[i])
        i++;
    return (i);
}

void launchCommand(char **tab, t_client *c)
{
    for (int i = 0; commands[i].command != NULL; i++) {
        if (strcmp(tab[0], commands[i].command) == 0) {
            (commands[i].func)(tab, c->fd);
            return;
        }
    }
}