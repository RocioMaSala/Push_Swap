/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:59:15 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/09 11:21:37 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(t_stack *a, int n)
{
	t_node	*curr;

	curr = a->front;
	while (curr)
	{
		if (curr->dato == n)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	parse_to_stack(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	char	**temp;
	long	val;

	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp && temp[j])
		{
			if (!is_valid_num(temp[j]))
				error_exit(a, NULL);
			val = ft_atol(temp[j]);
			if (val < -2147483648 || val > 2147483647 || has_duplicates(a,
					(int)val))
				error_exit(a, NULL);
			add_back(a, (int)val);
			free(temp[j]);
			j++;
		}
		free(temp);
		i++;
	}
}

static int	find_min_pos(t_stack *s)
{
	t_node	*tmp;
	int		min_val;
	int		min_pos;
	int		i;

	tmp = s->front;
	min_val = tmp->dato;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->dato < min_val)
		{
			min_val = tmp->dato;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	sort_five(t_stack *a, t_stack *b, t_bench *bench)
{
	int	min_pos;

	while (a->size > 3)
	{
		min_pos = find_min_pos(a);
		if (min_pos <= a->size / 2)
		{
			while (min_pos-- > 0)
				ra(a, bench);
		}
		else
		{
			min_pos = a->size - min_pos;
			while (min_pos-- > 0)
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	sort_three(a, bench);
	while (b->size > 0)
		pa(a, b, bench);
}
