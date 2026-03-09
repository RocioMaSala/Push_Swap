/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_combined.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:19:17 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/09 11:22:38 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	swap_silent(a);
	swap_silent(b);
	write(1, "ss\n", 3);
	if (bench && bench->active)
	{
		bench->ss++;
		bench->total++;
	}
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	rotate_silent(a);
	rotate_silent(b);
	write(1, "rr\n", 3);
	if (bench && bench->active)
	{
		bench->rr++;
		bench->total++;
	}
}

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	reverse_rotate_silent(a);
	reverse_rotate_silent(b);
	write(1, "rrr\n", 4);
	if (bench && bench->active)
	{
		bench->rrr++;
		bench->total++;
	}
}
