/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:23:45 by jgodino-          #+#    #+#             */
/*   Updated: 2026/03/09 11:23:48 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int		active;
}			t_bench;

void				add_back(t_stack *s, int dato);
void				parse_to_stack(int argc, char **argv, t_stack *a);
void				free_stack(t_stack *s);
void				initializer_stack(t_stack *s);

void				simple_algorithm(t_stack *a, t_stack *b, t_bench *bench);
void				medium_algorithm(t_stack *a, t_stack *b, t_bench *bench);
void				complex_algorithm(t_stack *a, t_stack *b, t_bench *bench);
void				sort_three(t_stack *a, t_bench *bench);
void				assign_index(t_stack *a);
void				adaptive_algorithm(t_stack *a, t_stack *b, char *forced,
						t_bench *bench);
float				compute_disorder(t_stack *a);
void				print_bench(float disorder, char *strat, char *comp,
						t_bench *b);

void				sa(t_stack *a, t_bench *bench);
void				sb(t_stack *b, t_bench *bench);
void				pa(t_stack *a, t_stack *b, t_bench *bench);
void				pb(t_stack *a, t_stack *b, t_bench *bench);
void				ra(t_stack *a, t_bench *bench);
void				rb(t_stack *b, t_bench *bench);
void				rra(t_stack *a, t_bench *bench);
void				rrb(t_stack *b, t_bench *bench);
void				ss(t_stack *a, t_stack *b, t_bench *bench);
void				rr(t_stack *a, t_stack *b, t_bench *bench);
void				rrr(t_stack *a, t_stack *b, t_bench *bench);

void				swap_silent(t_stack *s);
void				rotate_silent(t_stack *s);
void				reverse_rotate_silent(t_stack *s);

void				error_exit(t_stack *a, t_stack *b);

void				sort_five(t_stack *a, t_stack *b, t_bench *bench);
void				push_back_to_a(t_stack *a, t_stack *b, t_bench *bench);

#endif
