/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:56:00 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/23 13:46:40 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // Para malloc y free
# include <unistd.h>
# include <stdio.h>
# include <stddef.h> // Para size_t y NULL

typedef struct s_node
{
    int dato;
    struct s_node *next;
	struct s_node *prev;
}				t_node;

typedef struct s_stack
{
	t_node *front;
	t_node *last;
	int size;
}					t_stack;


int reverserotate(stack *rr);
node *new_node(int dato);
void add_back(stack *s, int dato);
void print_stack(stack *s);

#endif
