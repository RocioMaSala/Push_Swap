/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:40:31 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/09 12:34:51 by jgodino-         ###   ########.fr       */
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

static int	parse_flags(int argc, char **argv, t_bench *bench, char **forced)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			bench->active = 1;
		else
			*forced = argv[i];
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	char	*forced;
	int		i;

	if (argc < 2)
		return (0);
	initializer_stack(&a);
	initializer_stack(&b);
	ft_memset(&bench, 0, sizeof(t_bench));
	forced = NULL;
	i = parse_flags(argc, argv, &bench, &forced);
	parse_to_stack(argc - i + 1, &argv[i - 1], &a);
	if (a.size > 1)
	{
		assign_index(&a);
		adaptive_algorithm(&a, &b, forced, &bench);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
