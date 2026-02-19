/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:59:37 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/19 17:41:05 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initializer_stack(stack *a)
{
    s -> front = NULL;
    s -> size = 0;
}
void initializer_stack(stack *b)
{
    s -> front = NULL;
    s -> size = 0;
}
char push (stack *add, int x)
{
    node *new;
    
    new = malloc(sizeof(node));
    if (!new)
        return(NULL)
    new -> dato = x;
    new -> next = a -> front;
    a -> front = new;
    a -> size++;
    return (new);    
}

char pop (stack *delete, int x)
{
    /*MIRAR ESTE TEMA
    Tener siempre en cuenta: Solo podemos modificar el nodo primero!*/
    
 
}


void swapa (stack *swapa, int size)
{
    node *tmp;

    if (size > 1);
        break;
    tmp = push(swapa, a->front->dato);
    
    

    
    



    
}
