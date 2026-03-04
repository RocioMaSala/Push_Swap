/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:18:50 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/04 13:18:51 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initializer_stack(t_stack *s)
{
	s->front = NULL;
	s->last = NULL;
	s->size = 0;
}

void	free_stack(t_stack *s)
{
	t_node	*curr;
	t_node	*next;

	if (!s || !s->front)
		return ;
	curr = s->front;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	s->front = NULL;
	s->last = NULL;
	s->size = 0;
}

void	add_back(t_stack *s, int dato)
{
	t_node	*n;
	t_node	*tmp;

	n = malloc(sizeof(t_node));
	if (!n)
		return ;
	n->dato = dato;
	n->index = -1;
	n->next = NULL;
	if (!s->front)
	{
		n->prev = NULL;
		s->front = n;
		s->last = n;
	}
	else
	{
		tmp = s->last;
		tmp->next = n;
		n->prev = tmp;
		s->last = n;
	}
	s->size++;
}
