/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** my_str_to_word_array_utils
*/

#include "list.h"

int count_tab(char **tab)
{
    int i = 0;

    while (tab[i]) {
        i++;
    }
    return (i);
}

void check_gui(char const *str, int *i, int *words)
{
    if (str[*i] == '"') {
        *i += 1;
        for (; str[*i] != '"'; *i += 1);
        *i += 1;
        *words += 1;
    }
}

void check_gui2(char const *str, int *i)
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
        for (; str[*k] != '"'; *a += 1, *k += 1) {
            array[*a] = str[*k];
        }
        *k += 1;
    }
    return (array);
}