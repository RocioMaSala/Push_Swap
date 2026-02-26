#include "push_swap.h"

void swap_silent(t_stack *s)
{
    t_node *first;
    t_node *second;

    if (!s || s->size < 2)
        return ;
    first = s->front;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    else
        s->last = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    s->front = second;
}

void rotate_silent(t_stack *s)
{
    t_node *first;

    if (!s || s->size < 2)
        return ;
    first = s->front;
    s->front = first->next;
    s->front->prev = NULL;
    first->next = NULL;
    first->prev = s->last;
    s->last->next = first;
    s->last = first;
}

void reverse_rotate_silent(t_stack *s)
{
    t_node *last;

    if (!s || s->size < 2)
        return ;
    last = s->last;
    s->last = last->prev;
    s->last->next = NULL;
    last->prev = NULL;
    last->next = s->front;
    s->front->prev = last;
    s->front = last;
}