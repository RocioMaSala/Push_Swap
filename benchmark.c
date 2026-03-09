/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino- <jgodino-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:09:01 by romarti2          #+#    #+#             */
/*   Updated: 2026/03/09 11:24:36 by jgodino-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	print_bench_ops(t_bench *b)
{
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(b->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(b->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(b->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(b->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(b->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(b->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(b->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(b->rr, 2);
}

static void	print_bench_ops2(t_bench *b)
{
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(b->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(b->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(b->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(float disorder, char *strat, char *complexity, t_bench *b)
{
	if (!b || !b->active)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strat, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(b->total, 2);
	print_bench_ops(b);
	print_bench_ops2(b);
}
