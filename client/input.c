/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** input
*/

#include "include/client.h"

int loop(t_client *c)
{
    char *input = NULL;
    while (12)
    {
        input = prompt();
        if (!input)
            errorHandling("No input");
        if (input && input[0]) {
            printf("Please enter something.\n");
            continue;
        }
    }
    free(input);
    return (0);
}

char *prompt(void)
{
    char *line = malloc(sizeof(char) * 1024);
    if (line == NULL)
        errorHandling("Error Malloc Prompt");
    fgets(line, strlen(line), stdin);
    return (line);
}