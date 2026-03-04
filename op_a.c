/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:43:07 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/04 12:43:30 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap_silent(a);
	write(1, "sa\n", 3);
}

void	ra(t_stack *a)
{
	rotate_silent(a);
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	reverse_rotate_silent(a);
	write(1, "rra\n", 4);
}
