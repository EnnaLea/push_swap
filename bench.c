/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:01:49 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/14 23:52:40 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	if (!bench)
		return ;
	bench->enabled = 0;
	bench->strategy = STRATEGY_ADAPTIVE;
	bench->disorder = 0.0f;
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

static void	print_strategy_name(const t_bench *bench)
{
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (bench->strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("Simple / O(n²)\n", 2);
	else if (bench->strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("Intermediate / O(n√n)\n", 2);
	else if (bench->strategy == STRATEGY_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (bench->disorder < 0.20f)
			ft_putstr_fd("O(n²)\n", 2);
		else if (bench->disorder < 0.50f)
			ft_putstr_fd("O(n√n)\n", 2);
		else
			ft_putstr_fd("O(n log n)\n", 2);
	}
}

static void	bench_swaps(const t_bench *b)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(b->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(b->sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(b->ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(b->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(b->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	bench_rotates(const t_bench *b)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(b->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(b->rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(b->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(b->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(b->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(b->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_bench *bench)
{
	if (!bench || !bench->enabled)
		return ;
	// {
	// 	if (bench->count_only)
	// 	{
	// 		ft_putnbr_fd(bench->total, 2);
	// 		write (1, "\n", 1);
	// 	}
	// }
	else
	{
		ft_putstr_fd("[bench] disorder:  ", 2);
		ft_put_float_percent_fd(bench->disorder, 2);
		ft_putstr_fd("\n", 2);
		print_strategy_name(bench);
		ft_putstr_fd("[bench] total_ops: ", 2);
		ft_putnbr_fd(bench->total, 2);
		ft_putchar_fd('\n', 2);
		bench_swaps(bench);
		bench_rotates(bench);
	}

}
