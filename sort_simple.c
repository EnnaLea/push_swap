/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:50:02 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 22:59:13 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *s, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	if (!s || s->size < 3)
		return ;
	top = s->top->rank;
	mid = s->top->next->rank;
	bot = s->top->next->next->rank;
	if (top > mid && mid < bot && top < bot)
		op_sa(s, bench);
	else if (top > mid && mid < bot && top > bot)
		op_ra(s, bench);
	else if (top < mid && mid > bot && top > bot)
		op_rra(s, bench);
	else if (top > mid && mid > bot)
	{
		op_sa(s, bench);
		op_rra(s, bench);
	}
	else if (top < mid && mid > bot && bot > top)
	{
		op_rra(s, bench);
		op_sa(s, bench);
	}
}

void	sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*min;
	int		count;

	if (a->size <= 3)
	{
		sort_three(a, bench);
		return ;
	}
	count = a->size - 3;
	while (count--)
	{
		min = find_min(a);
		rotate_to_top(a, min, bench, 'a');
		op_pb(a, b, bench);
	}
	sort_three(a, bench);
	while (b->size > 0)
		op_pa(a, b, bench);
}
