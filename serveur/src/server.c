/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** server
*/
#include "../include/serveur.h"

int init_server(server_t *server, int port)
{
    server->proto = getprotobyname("TCP");
    server->port = port;
    server->sock_len = sizeof(server->s_in);
    server->sock_fd_s = socket(AF_INET, SOCK_STREAM, server->proto->p_proto);
    if (server->sock_fd_s == -1) {
        perror("socket");
        return (-1);
    }
    server->s_in.sin_family = AF_INET;
    server->s_in.sin_port = htons(server->port);
    server->s_in.sin_addr.s_addr = INADDR_ANY;
    if (bind(server->sock_fd_s, (const struct sockaddr *)&server->s_in,
        sizeof(server->s_in)) == -1 || listen(server->sock_fd_s, 42) == -1) {
            dprintf(2, "Port is invalid\n");
            return (-1);
    }
    return (0);
}

void serveur(int port)
{
    server_t server;

    if (init_server(&server, port) == -1)
        exit(84);
}