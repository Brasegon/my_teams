/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** list
*/

#ifndef LIST_H_
# define LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct		s_list
{
    struct s_list **last;
    struct s_list **first;
    struct s_list *next;
    struct s_list *prev;
    char msg[256];
    unsigned int		*size;
    struct s_list *(*get_nth)(struct s_list *, unsigned int);
    struct s_list *(*delete_nth)(struct s_list *, unsigned int);
    struct s_list *(*insert_at)(struct s_list *, unsigned int, void *);
    struct s_list *(*push_back)(struct s_list *, char *);
    struct s_list *(*push_front)(struct s_list *, char *);
    struct s_list *(*pop_back)(struct s_list *);
    struct s_list *(*pop_front)(struct s_list *);
    int			(*make_circular)(struct s_list *);
    int			(*get_size)(struct s_list *);
    void			(*destroy)(struct s_list *);
}			t_list;

t_list			*create_list(char *, t_list *);
t_list			*get_nth_list(t_list *, unsigned int);
t_list			*delete_nth_list(t_list *, unsigned int);
t_list			*insert_at_list(t_list *, unsigned int, void *);
t_list			*push_back_list(t_list *, char *);
t_list			*push_front_list(t_list *, char *);
t_list			*pop_back_list(t_list *);
t_list			*pop_front_list(t_list *);
int			make_circular_list(t_list *);
int			get_size_list(t_list *);
void			destroy_list(t_list *);
void			free_content(t_list *);

#endif /* !LIST_H_ */