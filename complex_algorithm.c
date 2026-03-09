/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:31:24 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/06 16:11:08 by romarti2         ###   ########.fr       */
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

static int	get_max_index_pos(t_stack *b)
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

void	push_back_to_a(t_stack *a, t_stack *b, t_bench *bench)
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
				rb(b, bench);
		}
		else
		{
			max_pos = size_b - max_pos;
			while (max_pos-- > 0)
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}

static int	get_max_bits(int num_max)
{
	int	max_bit;

	max_bit = 0;
	while ((num_max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	complex_algorithm(t_stack *a, t_stack *b, t_bench *bench)
{
	int	size;
	int	max_bit;
	int	i;
	int	j;

	size = a->size;
	max_bit = get_max_bits(size - 1);
	i = -1;
	while (++i < max_bit)
	{
		j = -1;
		while (++j < size)
		{
			if (((a->front->index >> i) & 1) == 1)
				ra(a, bench);
			else
				pb(a, b, bench);
		}
		while (b->size > 0)
			pa(a, b, bench);
	}
}
