/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:19:58 by jgodino-          #+#    #+#             */
/*   Updated: 2026/03/06 16:11:01 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	medium_algorithm(t_stack *a, t_stack *b)
{
	int	i;
	int	chunk_size;

	assign_index(a);
	if (a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = ft_sqrt(a->size);
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
