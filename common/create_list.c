/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** create_list
*/

#include "list.h"

void next_list(t_list *list)
{
    list->push_back = &push_back_list;
    list->push_front = &push_front_list;
    list->pop_back = &pop_back_list;
    list->pop_front = &pop_front_list;
    list->insert_at = &insert_at_list;
    list->make_circular = &make_circular_list;
    list->destroy = &destroy_list;
    list->get_nth = &get_nth_list;
    list->delete_nth = &delete_nth_list;
    list->get_size = &get_size_list;
}

t_list		*create_list(char *message, t_list *old)
{
    t_list	*list;

    if (!(list = malloc(sizeof(*list))) ||
        !(list->first = old ? old->first : malloc(sizeof(t_list *))) ||
        !(list->last = old ? old->last : malloc(sizeof(t_list *))) ||
        !(list->size = old ? old->size : malloc(sizeof(unsigned int))))
        return (NULL);
    !old ? *list->first = list : 0;
    !old ? *list->last = list : 0;
    !old ? *list->size = 1 : 0;
    strcpy(list->msg, message);
    list->next = NULL;
    list->prev = NULL;
    next_list(list);
    return (list);
}

void		destroy_list(t_list *this)
{
    t_list	*tmp;
    t_list	*back;
    unsigned int	i;

    if (!this)
        return ;
    free(this->last);
    free(this->first);
    free(this->size);
    back = this;
    i = 0;
    while (this != NULL && (this != back || !i)) {
        i = 1;
        tmp = this;
        this = this->next;
        free(tmp);
    }
}

t_list		*delete_nth_list(t_list *this, unsigned int n)
{
    t_list	*tmp;
    unsigned int	i;

    if (!this || !(tmp = *this->first))
        return (NULL);
    if (!n)
        return (pop_front_list(this));
    if (n >= *this->size - 1)
        return (pop_back_list(this));
    i = -1;
    while (tmp && ++i < n)
        if (!(tmp = tmp->next))
        return (NULL);
    tmp->prev ? tmp->prev->next = tmp->next : 0;
    tmp->next ? tmp->next->prev = tmp->prev : 0;
    free(tmp);
    return ((*this->size)--, *this->first);
}