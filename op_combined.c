/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_combined.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:19:17 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/06 16:08:29 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap_silent(a);
	swap_silent(b);
	write(1, "ss\n", 3);
	if (g_bench.active)
	{
		g_bench.ss++;
		g_bench.total++;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_silent(a);
	rotate_silent(b);
	write(1, "rr\n", 3);
	if (g_bench.active)
	{
		g_bench.rr++;
		g_bench.total++;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_silent(a);
	reverse_rotate_silent(b);
	write(1, "rrr\n", 4);
	if (g_bench.active)
	{
		g_bench.rrr++;
		g_bench.total++;
	}
}
