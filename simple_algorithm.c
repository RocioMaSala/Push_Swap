/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:27:26 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/06 18:36:46 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
