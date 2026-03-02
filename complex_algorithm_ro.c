/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_ro.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:51:38 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/26 13:53:47 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ksort(t_stack *a)
{
    t_stack *b;
    int sizea;
    int sizeb;
    int range;

    b = malloc(sizeof(t_stack));
    b->front = NULL;
    b->last = NULL;
    b -> size = 0;
    sizea = a->size;
    range = 1.3 * (sizea/5);
    assign_index(a);
    while ((a->size) > 0) // aquí vaciamos a
    {
        sizeb = b->size;
        if((a->front->index) >= (sizeb + range))
            ra (a);
        else if (((a->front->index) > sizeb) && ((a->front->index) < (sizeb + range)))
        {
            pb (a,b);  
        }
        else if ((a->front->index) <= sizeb)
        {
            pb (a,b);
            rb (b);
        }
    }
    while ((b->size) > 0)
}