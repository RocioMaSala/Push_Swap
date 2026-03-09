/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:27:26 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/09 11:21:16 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_core(t_stack *a, t_bench *bench)
{
	int	f;
	int	s;
	int	t;

	f = a->front->dato;
	s = a->front->next->dato;
	t = a->last->dato;
	if (f > s && s < t && f < t)
		sa(a, bench);
	else if (f > s && s > t)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (f > s && s < t && f > t)
		ra(a, bench);
	else if (f < s && s > t && f < t)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (f < s && s > t && f > t)
		rra(a, bench);
}

void	sort_three(t_stack *a, t_bench *bench)
{
	if (a->size != 3)
		return ;
	sort_three_core(a, bench);
}

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (16);
	return (35);
}

void	simple_algorithm(t_stack *a, t_stack *b, t_bench *bench)
{
	int	i;
	int	chunk_size;

	assign_index(a);
	chunk_size = get_chunk_size(a->size);
	i = 0;
	while (a->size > 0)
	{
		if (a->front->index <= i)
		{
			pb(a, b, bench);
			rb(b, bench);
			i++;
		}
		else if (a->front->index <= i + chunk_size)
		{
			pb(a, b, bench);
			i++;
		}
		else
			ra(a, bench);
	}
	push_back_to_a(a, b, bench);
}
