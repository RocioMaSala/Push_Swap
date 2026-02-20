/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:59:37 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/20 14:47:23 by romarti2         ###   ########.fr       */
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

int isempty (stack *verify)
{
    if (verify->front = NULL)
        return (1);
    return (0);
}

int push (stack *add, int x)
{
    node *new;
    
    new = malloc(sizeof(node));
    if (!new)
        return(0)
    new -> dato = x;
    new -> next = add -> front;
    add -> front = new;
    add -> size++;
    return (1);    
}


int peek(stack *top) // Para saber qué nodo está en el top de la lista 
{
    if (!top || top->front == NULL)
        return 0;
    return (top->front->data);  
}


int pop (stack *delete) // Elimina y devuelve el elemento encima pila
{ 
    node *tmp;
    int datatemp;
    
    if(!delete ||delete->front == NULL) // Comprobar que la lista no esté vacía
        return (0);
    tmp = delete->front;
    datatemp = delete->front->dato;
    delete->front = tmp->next;
    free (tmp);
    delete -> size--; 
    return (datatemp);
}


void swapa (stack *swapa, int size) // está mal esto
{
    node *first;
    node *second;
    node *tmp;

    if (size > 1)
        return;
    first = swapa -> front;
    second = first -> next;

    
    tmp = second;
    second = first;
    first = tmp;
    free (tmp); 
}
