/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** commands
*/

#include "include/client.h"

int countTab(char **tab)
{
    int i = 0;
    while (tab[i])
        i++;
    return (i);
}