/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** main
*/
#include "include/client.h"

void print_usage(void)
{
    printf("USAGE: USAGE: ./myteams_cli ip port\n \
    \tip is the server ip address on which the server socket listens\n \
    \tport is the port number on which the server socket listens");
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (strcmp(av[1], "-help") == 0) {
            print_usage();
        }
        return (0);
    } else
        return (84);
}