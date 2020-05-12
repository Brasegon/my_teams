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
    if (ac != 3) {
        print_usage();
        if (ac == 2 && strcmp(av[1], "-help") == 0)
            return (0);
        return (84);
    }
    t_client *client = malloc(sizeof(t_client));
    if (client == NULL) {
        perror("Main Malloc");
        exit (84);
    }
    client->ip = av[1];
    client->port = atoi(av[2]);
    initClient(client);
    free(client);
    return (0);
}