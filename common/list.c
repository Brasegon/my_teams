/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** list
*/

#include "list.h"

t_list		*get_nth_list(t_list *this, unsigned int n)
{
    t_list	*tmp;
    unsigned int i = 0;

    if (!this || !(tmp = *this->first))
        return (NULL);
    while (tmp && i < n) {
        i++;
        tmp = tmp->next;
    }
    return (tmp);
}

int		make_circular_list(t_list *this)
{
    if (!this || !*this->first || !this->last)
        return (-1);
    (*this->last)->next = *this->first;
    (*this->first)->prev = *this->last;
    return (0);
}

t_list		*insert_at_list(t_list *this, unsigned int n, void *struc)
{
    t_list	*elem;
    t_list	*tmp;
    unsigned int i = -1;

    if (!this || !(tmp = *this->first))
        return (NULL);
    if (!n)
        return (push_front_list(this, struc, 0));
    if (n >= *this->size - 1)
        return (push_back_list(this, struc, 0));
    if (!(elem = create_list(struc, 0, this)))
        return (NULL);
    while (tmp && ++i < n - 1)
        if (!(tmp = tmp->next))
        return (NULL);
    elem->next = tmp->next;
    elem->prev = tmp;
    tmp->next ? tmp->next->prev = elem : 0;
    tmp->next = elem;
    return ((*this->size)++, *this->first);
}

int		get_size_list(t_list *this)
{
    if (this)
        return (*this->size);
    return (-1);
}