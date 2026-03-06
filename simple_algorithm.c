/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:27:26 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/06 16:10:42 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *s)
{
	t_node	*tmp;
	int		min_val;
	int		min_pos;
	int		i;

	if (!s || !s->front)
		return (-1);
	tmp = s->front;
	min_val = tmp->dato;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->dato < min_val)
		{
			min_val = tmp->dato;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size != 3)
		return ;
	first = a->front->dato;
	second = a->front->next->dato;
	third = a->last->dato;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->size > 3)
	{
		min_pos = find_min_pos(a);
		if (min_pos <= a->size / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
		{
			min_pos = a->size - min_pos;
			while (min_pos-- > 0)
				rra(a);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	simple_algorithm(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk_size;

	assign_index(a);
	if (a->size <= 100)
		chunk_size = 16;
	else
		chunk_size = 35;
	i = 0;
	while (a->size > 0)
	{
		if (a->front->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->front->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	push_back_to_a(a, b);
}
