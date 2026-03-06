/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:40:31 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/06 14:45:21 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*forced;
	int		i;

	if (argc < 2)
		return (0);
	initializer_stack(&a);
	initializer_stack(&b);
	forced = NULL;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			g_bench.active = true;
		else
			forced = argv[i];
		i++;
	}
	parse_to_stack(argc - i + 1, &argv[i - 1], &a);
	if (a.size > 1)
	{
		assign_index(&a);
		adaptive_algorithm(&a, &b, forced);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
