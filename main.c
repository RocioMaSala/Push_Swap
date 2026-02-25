/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:55:38 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/25 16:54:39 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node *new_node(int dato)
{
    node *n;
    
    n = malloc(sizeof(node));
    if (!n)
        return (NULL);
    n->dato = dato;
    n->next = NULL;
    return (n);
}

void add_back(stack *s, int dato)
{
    node *n = new_node(dato);
    node *tmp;

    if (!s->front)
        s->front = n;
    else
    {
        tmp = s->front;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = n;
    }
    s->size++;
}

void print_stack(stack *s)
{
    node *tmp = s->front;

    while (tmp)
    {
        printf("%d ", tmp->dato);
        tmp = tmp->next;
    }
    printf("\n");
}
// ---------- MAIN ----------

int main(void)
{
    stack a;
    stack b;

    a.front = NULL;
    a.size = 0;
    b.front = NULL;
    b.size = 0;

    add_back(&a, 10);
    add_back(&a, 20);
    add_back(&a, 30);
    add_back(&a, 40);
    add_back(&b, 50);
    add_back(&b, 60);
    add_back(&b, 70);

    printf("Antes:\n");
    print_stack(&a);
    print_stack(&b); 

    reverse_rotate(&a);

    printf("Después:\n");
    print_stack(&a);
    print_stack(&b);

    return (0);
}

