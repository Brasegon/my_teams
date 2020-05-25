/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019 [WSL: Debian]
** File description:
** test
*/
#include "list.h"

#include <unistd.h>
#include <stdlib.h>

static int is_alphanum(char c)
{
    if ((c >= '0' && c <= '9') || c == '"' || c == '-' || c == '/')
        return (1);
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

static int nb_words(char const *str)
{
    int i = 0;
    int words = 0;
    while (str[i] != '\0') {
        check_gui(str, &i, &words);
        if (is_alphanum(str[i]) == 1)
            words += 1;
        while (is_alphanum(str[i]) == 1 && str[i] != '\0')
            i += 1;
        if (str[i] != '\0')
            i += 1;
    }
    return (words);
}

static int word_len(char const *str, int k)
{
    int z = 0;
    while (str[k] != '\0') {
        check_gui2(str, &k);
        if (is_alphanum(str[k]) != 1)
                return (z);
        z += 1;
        k++;
    }
    return (z);
}

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (nb_words(str) + 1));
    int i = 0;
    for (int k = 0, a = 0; i != nb_words(str); i += 1) {
        a = 0;
        for (;is_alphanum(str[k]) == 0; k += 1);
        array[i] = malloc(sizeof(char) * (word_len(str, k) + 1));
        array[i] = add_char_gui(array[i], str, &a, &k);
        for (;is_alphanum(str[k]) == 1; a += 1, k += 1)
            array[i][a] = str[k];
        array[i][a] = '\0';
    }
    array[i] = NULL;
    return (array);
}