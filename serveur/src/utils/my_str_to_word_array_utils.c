/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** my_str_to_word_array_utils
*/

#include "../../include/serveur.h"

void check_gui(char const *str, int *i)
{
    if (str[*i] == '"') {
        *i += 1;
        for (; str[*i] != '"'; *i += 1);
        *i += 1;
    }
}

char *add_char_gui(char *array, char const *str, int *a, int *k)
{
    if (str[*k] == '"') {
        *k += 1;
        for (; str[*k] != '"'; *a += 1, *k += 1)
            array[*a] = str[*k];
        *k += 1;
    }
    return (array);
}