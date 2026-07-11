/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:50:02 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/11 21:43:55 by ealiman          ###   ########.fr       */
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
	//[0,2,1]
	if (top < mid && mid > bot && top < bot)
	{
		op_sa(s, bench);
		op_ra(s, bench);
	}
	//[2,1,0]
	else if (top > mid && mid > bot && mid < top)
	{
		op_sa(s, bench);
		op_ra(s, bench);
	}
	//[1, 0, 2]
	else if (top > mid && mid < bot && top < bot)
		op_sa(s, bench);
	//[2,0,1]
	else if (top > mid && mid < bot && top > bot)
		op_ra(s, bench);
	//[1, 2, 0]
	else if (top < mid && mid > bot && bot < top)
		op_rra(s, bench);
}

void	sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{

}