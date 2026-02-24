#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b || b->size == 0 || !b->front)
		return ;
	tmp = b->front;
	b->front = tmp->next;
	if (b->front)
		b->front->prev = NULL;
	else
		b->last = NULL;
	b->size--;
	tmp->next = a->front;
	if (a->front)
		a->front->prev = tmp;
	else
		a->last = tmp;
	a->front = tmp;
	tmp->prev = NULL;
	a->size++;
	write(1, "pa\n", 3);
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
