/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:19:58 by jgodino-          #+#    #+#             */
/*   Updated: 2026/03/09 11:25:20 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (ft_sqrt(size));
}

void	medium_algorithm(t_stack *a, t_stack *b, t_bench *bench)
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
