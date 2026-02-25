/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:31:00 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/24 16:32:05 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int sa(stack *swap)
{
    node *first;
    node *second;

    if (!swap || swap -> size < 2)
        return(0);
    first = swap -> front;
    second = first -> next;// En un nodo si que hay next, pero en una pila no, por eso poner swapa -> next, no tiene sentido 
    first -> next = second -> next;
    second -> next = first;
    swap -> front = second;
    return (1);
}

int pa(stack *pusha, stack *pushb)
{
    node *firsta;
    node *firstb;

    if (!pushb)
        return (0);
    firstb = pushb -> front;
    pushb -> front = firstb -> next; 
    firstb -> next = pusha-> front;
    pusha-> front = firstb;
    return (1);
       
}

int ra(stack *rotate)
{
    node *last;
    node *first;
    node *second;

    if (!rotate)
        return (0);
    first = rotate -> front;
    second = first -> next;
    last = rotate -> front;
    rotate -> front = second;
    while (last->next != NULL)
         last = last -> next;
    last -> next = first;
    first -> next = NULL;
    return (1);
}

int rra(stack *rr) 
{
    node *last;
    node *prev; // Para gestionar el antepenúltimo

    prev = NULL;
    last = rr -> front;
    while (last->next != NULL)
    {
        prev = last;
        last = last -> next;
    }    
    prev -> next = NULL;
    last -> next = rr -> front;
    rr -> front = last;
    return (1);
}
