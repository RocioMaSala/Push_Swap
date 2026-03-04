/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:32:12 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/04 13:32:35 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	sb(t_stack *b)
{
	swap_silent(b);
	write(1, "sb\n", 3);
}

void	rb(t_stack *b)
{
	rotate_silent(b);
	write(1, "rb\n", 3);
}

void	rrb(t_stack *b)
{
	reverse_rotate_silent(b);
	write(1, "rrb\n", 4);
}
