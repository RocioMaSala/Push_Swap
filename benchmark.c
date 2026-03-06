/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com:w  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:09:01 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/06 16:09:01 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench		g_bench = {0};

static void	print_percent(float disorder)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)(disorder * 100);
	decimal_part = (int)(disorder * 10000) % 100;
	ft_putnbr_fd(integer_part, 2);
	ft_putchar_fd('.', 2);
	if (decimal_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal_part, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_bench(float disorder, char *strat, char *complexity)
{
	if (!g_bench.active)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strat, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(g_bench.total, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(g_bench.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(g_bench.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(g_bench.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(g_bench.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(g_bench.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(g_bench.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(g_bench.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(g_bench.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(g_bench.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(g_bench.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(g_bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}
