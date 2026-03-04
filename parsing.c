/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:59:15 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/04 13:00:23 by romarti2         ###   ########.fr       */
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
