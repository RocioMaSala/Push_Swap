/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:31:24 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/04 13:21:06 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	t_node	*curr;
	t_node	*compare;
	int		index;

	if (!a || !a->front)
		return ;
	curr = a->front;
	while (curr)
	{
		index = 0;
		compare = a->front;
		while (compare)
		{
			if (curr->dato > compare->dato)
				index++;
			compare = compare->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

int	get_range(t_stack *s)
{
	if (s->size <= 100)
		return (15);
	return (35);
}

int	get_max_index_pos(t_stack *b)
{
	t_node	*tmp;
	int		max_idx;
	int		pos;
	int		i;

	tmp = b->front;
	max_idx = -1;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index > max_idx)
		{
			max_idx = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	size_b;

	while (b->size > 0)
	{
		max_pos = get_max_index_pos(b);
		size_b = b->size;
		if (max_pos <= size_b / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			max_pos = size_b - max_pos;
			while (max_pos-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	complex_algorithm(t_stack *a, t_stack *b)
{
	int size;
	int num_max;
	int max_bit;
	int i;
	int j;

	size = a->size;
	num_max = size - 1;
	max_bit = 0;
	i = 0;
	while((num_max >> max_bit) != 0)
		max_bit++;
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			if(((a->front->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size > 0)
			pa(a,b);	
		i++;
	}
}
