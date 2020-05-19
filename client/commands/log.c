/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** Login and Logout
*/

#include "../include/client.h"

void login(char **tab, int fd)
{
    if (tab[1] != NULL) {
        sendMessage(fd, tab[1]);
        printf("[CLIENT] Sending login informations....");
    } else {
        printf("Please provide an username. (/login [name])\n");
    }
}

void logout(char **tab, int fd)
{
    
}