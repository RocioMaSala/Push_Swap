#include "push_swap.h"

void sb(t_stack *b)
{
    t_node *first;
    t_node *second;

    if (!b || b->size < 2)
        return ;
    first = b->front;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    b->front = second;
    write(1, "sb\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || a->size == 0 || !a->front)
		return ;
	tmp = a->front;
	a->front = tmp->next;
	if (a->front)
		a->front->prev = NULL;
	else
		a->last = NULL;
	a->size--;
	tmp->next = b->front;
	if (b->front)
		b->front->prev = tmp;
	else
		b->last = tmp;
	b->front = tmp;
	tmp->prev = NULL;
	b->size++;
	write(1, "pb\n", 3);
}

void rb(t_stack *b)
{
    t_node *first;

    if (!b || b->size < 2)
        return ;
    first = b->front;
    b->front = first->next;
    b->front->prev = NULL;
    first->next = NULL;
    first->prev = b->last;
    b->last->next = first;
    b->last = first;
    write(1, "rb\n", 3);
}

void rrb(t_stack *b)
{
    t_node *last;

    if (!b || b->size < 2)
        return ;
    last = b->last;
    b->last = last->prev;
    b->last->next = NULL;
    last->prev = NULL;
    last->next = b->front;
    b->front->prev = last;
    b->front = last;
    write(1, "rrb\n", 4);
}
