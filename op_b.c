/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:32:12 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/09 11:22:55 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b, t_bench *bench)
{
	swap_silent(b);
	write(1, "sb\n", 3);
	if (bench && bench->active)
	{
		bench->sb++;
		bench->total++;
	}
}

void	rb(t_stack *b, t_bench *bench)
{
	rotate_silent(b);
	write(1, "rb\n", 3);
	if (bench && bench->active)
	{
		bench->rb++;
		bench->total++;
	}
}

void	rrb(t_stack *b, t_bench *bench)
{
	reverse_rotate_silent(b);
	write(1, "rrb\n", 4);
	if (bench && bench->active)
	{
		bench->rrb++;
		bench->total++;
	}
}
