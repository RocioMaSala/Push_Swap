/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:27:26 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/26 15:48:36 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort (t_stack *stacka, int size)
{
	int i;
	int j;
	int rotation;
	
	if (!stacka || !stacka->front || size < 2)
    	return;
	j = 0;
	rotation = 0;
	while (j < (size - 1))
	{
		i = 0;
		while (i < (size - j - 1))
		{
			if ((stacka->front->dato)>(stacka->front->next->dato))
				sa(stacka);
			ra (stacka);
			rotation++;
			i++;
		}
		while (rotation > 0)
		{
			rra (stacka);
			rotation--;
		}
		j++;
	}
}


void push_front(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;

    new_node->dato = value;
    new_node->next = stack->front;
    stack->front = new_node;
}
/*
void print_stack(t_stack *stack)
{
    t_node *current;

    current = stack->front;
    while (current)
    {
        printf("%d ", current->dato);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    t_stack a;
    a.front = NULL;

    // Insertamos números en el stack
    push_front(&a, 1);
    push_front(&a, 6);
    push_front(&a, 5);
    push_front(&a, 1);

    printf("Stack inicial: ");
    print_stack(&a);

    bubble_sort(&a, 4);

    printf("Stack ordenado: ");
    print_stack(&a);

    return 0;
}*/