/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:36:15 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/02 17:42:53 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_algorithm(t_stack *a, t_stack *b)
{
	int	disorder;

	if (!a || a->size <= 1)
		return ;
	disorder = compute_disorder(a);
	if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		medium_algorithm(a, b);
	else if (disorder < 2)
		simple_algorithm(a, a->size);
	else
		complex_algorithm(a, b);
}
