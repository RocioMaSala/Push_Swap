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

void adaptive_algorithm (t_stack *a, t_stack *b)
{
    int disorder_index;

    disorder_index = compute_disorder(a);
    if (!a || !b)
        return (0);
    if (disorder_index < 0.2)
        simple_algorithm (a, a->size);
    else if (0.2 >= disorder_index > 0.5)
        medium_algorithm (a, b);
    else 
        complex_algorithm (a, b);  
}