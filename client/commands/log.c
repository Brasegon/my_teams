/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** Login and Logout
*/

#include "../include/client.h"

void login(int fd, char *str)
{
    if (str != NULL) {
        sendMessage(fd, str);
        printf("[CLIENT] Sending login informations....");
    }
}

char *logout(char *str)
{
    
}