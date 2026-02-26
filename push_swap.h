/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:56:00 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/26 16:25:36 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // Para malloc y free
# include <unistd.h>
# include <stdio.h>
# include <stddef.h> // Para size_t y NULL
# include <stdbool.h>

typedef struct s_node
{
    int             dato;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
    t_node  *front;
    t_node  *last;
    int     size;
}   t_stack;

t_node  *new_node(int dato);
void    add_back(t_stack *s, int dato);
void    print_stack(t_stack *s);
int     push (t_stack *add, int x);
void bubble_sort (t_stack *stacka, int size);


int    sa(t_stack *a);
int    ra(t_stack *a);
int    rra(t_stack *a);

void    sb(t_stack *b);
void    rb(t_stack *b);
void    rrb(t_stack *b);

int    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);

void    ss(t_stack *a, t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rrr(t_stack *a, t_stack *b);

#endif
