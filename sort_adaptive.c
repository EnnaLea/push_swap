/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:46:13 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/14 12:47:41 by ealiman          ###   ########.fr       */
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

static float low(int size)
{
	if (size <= 20)
		return (1.00f);
	if (size <= 35)
		return (0.15f);
	if (size <= 120)
		return (0.12f);
	return (0.07f);
	
}

static float high(int size)
{
	if (size <= 20)
		return (0.00f);
	if (size <= 59)
		return (0.77f);
	if (size <= 120)
		return (0.90f);
	if (size <= 150)
		return (0.87f);
	return (0.92f);
}

static void	apply_strategy(t_stack *a, t_stack *b, t_bench *bench,
		float disorder)
{
	int size;
	float lo;
	float hi;

	size = a->size;
	
	bench->disorder = disorder;
	if (size >= 500)
	{
		if (disorder >= 0.99f)
			return (bench->strategy = STRATEGY_SIMPLE, 
				sort_simple(a, b, bench));
		if (disorder <= 0.07f)
			return (bench->strategy = STRATEGY_COMPLEX, 
				sort_complex(a, b, bench));
		bench->strategy = STRATEGY_COMPLEX;
		return (sort_complex(a, b, bench));
	}
	lo = low(size);
	hi = high(size);
	if (disorder <= lo || disorder >= hi)
		return (bench->strategy = STRATEGY_SIMPLE,
			sort_simple(a, b, bench));
	bench->strategy = STRATEGY_MEDIUM;
	sort_medium(a, b, bench);
	
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
