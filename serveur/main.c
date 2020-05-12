/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** main
*/
#include "include/serveur.h"

void print_usage(void)
{
    printf("USAGE: ./myteams_server port\n\tport \
    is the port number on which the server socket listens.\n");
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (strcmp(av[1], "-help") == 0) {
            print_usage();
        }
        serveur(atoi(av[1]));
        return (0);
    } else
        return (84);
}