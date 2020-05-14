/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** commands
*/

#include "include/client.h"
#include "include/commands.h"

const t_commands commands[] =
{
    {"/login", &login},
    {"logout"},
    {"/use"},
    {"/help"},
    {"/users"},
    {"/user"},
    {"/send"},
    {"/messages"},
    {"/subscribed"},
    {"/subscribe"},
    {"/unsubscribe"},
    {"/create"},
    {"/list"},
    {"/info"},
    {NULL, NULL}
};

void sendMessage(int fd, char *message)
{
    dprintf(fd, "%s", message);
}