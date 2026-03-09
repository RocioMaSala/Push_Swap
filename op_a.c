/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:43:07 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/09 11:22:48 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_bench *bench)
{
	swap_silent(a);
	write(1, "sa\n", 3);
	if (bench && bench->active)
	{
		bench->sa++;
		bench->total++;
	}
}

void	ra(t_stack *a, t_bench *bench)
{
	rotate_silent(a);
	write(1, "ra\n", 3);
	if (bench && bench->active)
	{
		bench->ra++;
		bench->total++;
	}
}

void	rra(t_stack *a, t_bench *bench)
{
	reverse_rotate_silent(a);
	write(1, "rra\n", 4);
	if (bench && bench->active)
	{
		bench->rra++;
		bench->total++;
	}
}
