/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** main
*/
#include "include/serveur.h"
#include <signal.h>

void signal_callback(int theSignal)
{
    if (theSignal == 11)
        exit(0);
}

void setHandler()
{
    struct sigaction sa;
    sa.sa_handler = signal_callback;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGSEGV, &sa, NULL) != 0)
        exit(0);
}

void print_usage(void)
{
    printf("USAGE: ./myteams_server port\n\tport \
    is the port number on which the server socket listens.\n");
}

int main(int ac, char **av)
{
    setHandler();
    if (ac == 2) {
        if (strcmp(av[1], "-help") == 0) {
            print_usage();
        }
        serveur(atoi(av[1]));
        return (0);
    } else
        return (84);
}