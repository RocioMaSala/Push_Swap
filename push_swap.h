/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:56:00 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/06 16:14:40 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				dato;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*front;
	t_node			*last;
	int				size;
}					t_stack;

void				add_back(t_stack *s, int dato);
void				parse_to_stack(int argc, char **argv, t_stack *a);
void				free_stack(t_stack *s);
void				initializer_stack(t_stack *s);

void				simple_algorithm(t_stack *a, t_stack *b);
void				medium_algorithm(t_stack *a, t_stack *b);
void				complex_algorithm(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
void				assign_index(t_stack *a);
void				adaptive_algorithm(t_stack *a, t_stack *b, char *forced);
float				compute_disorder(t_stack *a);
void				print_bench(float disorder, char *strat, char *complexity);

void				sa(t_stack *a);
void				sb(t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);

void				swap_silent(t_stack *s);
void				rotate_silent(t_stack *s);
void				reverse_rotate_silent(t_stack *s);

void				error_exit(t_stack *a, t_stack *b);

void				sort_five(t_stack *a, t_stack *b);
void				push_back_to_a(t_stack *a, t_stack *b);

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	bool	active;
}			t_bench;

extern t_bench	g_bench;

#endif
