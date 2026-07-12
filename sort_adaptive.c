/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:46:13 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 22:57:41 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_small_or_sorted(t_stack *a, t_stack *b, t_bench *bench)
{
	if (stack_is_sorted(a))
		return (1);
	if (a->size <= 3)
	{
		sort_three(a, bench);
		return (1);
	}
	return (0);
}

static void	apply_strategy(t_stack *a, t_stack *b, t_bench *bench,
		float disorder)
{
	bench->disorder = disorder;
	if (disorder < DISORDER_LOW)
	{
		bench->strategy = STRATEGY_SIMPLE;
		sort_simple(a, b, bench);
	}
	else if (disorder < DISORDER_MED)
	{
		bench->strategy = STRATEGY_MEDIUM;
		sort_medium(a, b, bench);
	}
	else
	{
		bench->strategy = STRATEGY_COMPLEX;
		sort_complex(a, b, bench);
	}
}

void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench)
{
	float	disorder;

	if (!a || !b)
		return ;
	if (handle_small_or_sorted(a, b, bench))
		return ;
	disorder = compute_disorder(a);
	apply_strategy(a, b, bench, disorder);
}
