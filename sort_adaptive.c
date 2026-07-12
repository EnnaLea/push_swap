/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:46:13 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 18:14:20 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_adaptive(t_stack *a, t_stack *b, t_bench *bench)
{
	float	disorder;

	if (!a || !b)
		return;
	if (stack_is_sorted(a))
		return ;
	if (a->size <= 3)
	{
		sort_three(a, bench);
		return ;
	}
	disorder = compute_disorder(a);
	bench->disorder = disorder;
	if(disorder < DISORDER_LOW)
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