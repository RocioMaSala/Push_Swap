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

void ksort(t_stack a)
{
    t_stack *b;
    int sizea;
    int sizeb;
    int range;
    int index;

    b->front = NULL;
    b->last = NULL;
    sizea = a->size;
    range = 1.3 * (sizea/5);
    while (/*algo tengo que escribir aquí*/)
    {
        sizeb = b->size; // Ventana mínima, sizeb tiene que ir aumentando o no, es variable.
        if(index >= (sizeb + range))
            ra (a);
        else if ((index > sizeb) && (index < (sizeb + range)))
        {
            pb (a);
            
        }
        else if (index <= sizeb)
        {
            pb (a);
            rb (b);
        }
        index++; // El index tope es n-1... esto sirve para el while?
    }





    







}