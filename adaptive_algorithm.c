/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:36:15 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/06 12:07:17 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_node	*i;
	t_node	*j;

	if (!a || a->size < 2)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = a->front;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->dato > j->dato)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((float)mistakes / total_pairs);
}

void	adaptive_algorithm(t_stack *a, t_stack *b, char *forced)
{
	float	d;
	char	*strat;
	char	*comp;

	d = compute_disorder(a);
	strat = "Adaptative";
	comp = "O(n log n)";
	if (forced && ft_strncmp(forced, "--simple", 8) == 0)
	{
		strat = "Simple";
		comp = "O(n^2)";
		simple_algorithm(a, b);
	}
	else if (forced && ft_strncmp(forced, "--medium", 8) == 0)
	{
		strat = "Medium";
		comp = "O(n√n)";
		medium_algorithm(a, b);
	}
	else if (forced && ft_strncmp(forced, "--complex", 9) == 0)
	{	
		strat = "Complex";
		comp = "O(n log n)";
		complex_algorithm(a, b);
	}
	else
	{
		if (a->size == 3)
		{
			sort_three(a);
			comp = "O(1)";
		}
		else if (a->size <= 5)
		{		
			sort_five(a, b);
			comp = "O(n)";
		}
		else if (d < 0.2)
		{
			simple_algorithm(a, b);
			comp = "O(n^2)";
		}
		else if (d < 0.5)
		{
			medium_algorithm(a, b);
			comp = "O(n√n)";
		}
		else
		{
			complex_algorithm(a, b);
			comp = "O(n log n)";
		}
	}
	if(g_bench.active)
		print_bench(d, strat, comp);
}
