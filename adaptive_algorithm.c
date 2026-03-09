/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:36:15 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/09 11:27:20 by jgodino-         ###   ########.fr       */
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

static char	*run_forced(t_stack *a, t_stack *b, char *f, t_bench *bench)
{
	if (ft_strncmp(f, "--simple", 8) == 0)
	{
		simple_algorithm(a, b, bench);
		return ("O(n^2)");
	}
	if (ft_strncmp(f, "--medium", 8) == 0)
	{
		medium_algorithm(a, b, bench);
		return ("O(n√n)");
	}
	if (ft_strncmp(f, "--complex", 9) == 0)
	{
		complex_algorithm(a, b, bench);
		return ("O(n log n)");
	}
	return (NULL);
}

static char	*run_auto(t_stack *a, t_stack *b, float d, t_bench *bench)
{
	if (a->size == 3)
	{
		sort_three(a, bench);
		return ("O(1)");
	}
	if (a->size <= 5)
	{
		sort_five(a, b, bench);
		return ("O(n)");
	}
	if (d < 0.2)
	{
		simple_algorithm(a, b, bench);
		return ("O(n^2)");
	}
	if (d < 0.5)
	{
		medium_algorithm(a, b, bench);
		return ("O(n√n)");
	}
	complex_algorithm(a, b, bench);
	return ("O(n log n)");
}

void	adaptive_algorithm(t_stack *a, t_stack *b, char *f, t_bench *bench)
{
	float	d;
	char	*comp;

	d = compute_disorder(a);
	comp = NULL;
	if (f)
		comp = run_forced(a, b, f, bench);
	if (!comp)
		comp = run_auto(a, b, d, bench);
	if (bench->active)
		print_bench(d, "Adaptative", comp, bench);
}
