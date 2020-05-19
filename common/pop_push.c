/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** pop_push
*/
#include "list.h"
void		free_content(t_list *list)
{
    t_list	*tmp;

    tmp = list;
    while (tmp) {
        memset(tmp->msg, 0, 256);
        tmp = tmp->next;
    }
}

t_list		*push_back_list(t_list *this, char *msg, int fd)
{
    t_list	*elem;

    if (!this || !*this->last || !(elem = create_list(msg, fd, this)))
        return (NULL);
    elem->prev = (*this->last);
    (*this->last)->next ? elem->next = (*this->last)->next : 0;
    (*this->last)->next ? elem->next->prev = elem : 0;
    (*this->last)->next = elem;
    (*this->last) = elem;
    return ((*this->size)++, *this->first);
}

t_list		*push_front_list(t_list *this, char *msg, int fd)
{
    t_list	*elem;

    if (!this || !(elem = create_list(msg, fd, this)))
        return (NULL);
    elem->next = *this->first;
    elem->prev = (*this->first)->prev;
    (*this->first)->prev ? (*this->first)->prev->next = elem : 0;
    (*this->first)->prev = elem;
    (*this->first) = elem;
    return ((*this->size)++, (*this->first));
}

t_list		*pop_back_list(t_list *this)
{
    t_list	*tmp;
    t_list	*ret;

    if (!this || !(tmp = *this->last))
        return (NULL);
    if (*this->size == 1) {
        this->destroy(this);
        return (NULL);
    }
    tmp->next ? tmp->next->prev = tmp->prev : 0;
    tmp->prev ? tmp->prev->next = tmp->next : 0;
    *this->last = tmp->prev;
    ret = *this->first;
    free(tmp);
    if (ret)
        (*ret->size)--;
    return (ret);
}

t_list		*pop_front_list(t_list *this)
{
    t_list	*tmp;
    t_list	*ret;

    if (!this || !(tmp = *this->first))
        return (NULL);
    if (*this->size == 1) {
        this->destroy(this);
        return (NULL);
    }
    tmp->next ? tmp->next->prev = tmp->prev : 0;
    tmp->prev ? tmp->prev->next = tmp->next : 0;
    *this->first = tmp->next;
    ret = *this->first;
    free(tmp);
    if (ret)
        (*ret->size)--;
    return (ret);
}