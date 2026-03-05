/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com:w  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:58:34 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/04 12:58:34 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!b || b->size == 0)
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
	if(g_bench.active)
	{
		g_bench.pa++;
		g_bench.total++;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a || a->size == 0)
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
	if(g_bench.active)
	{
		g_bench.pb++;
		g_bench.total++;
	}
}
