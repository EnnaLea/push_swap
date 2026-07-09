/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:03:47 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/09 17:19:37 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *s)
{
	int	tmp_value;
	int	tmp_rank;

	if (!s || s->size < 2)
		return ;
	tmp_value = s->top->value;
	tmp_rank = s->top->rank;
	s->top->value = s->top->next->value;
	s->top->rank = s->top->next->rank;
	s->top->next->value = tmp_value;
	s->top->next->rank = tmp_rank;
}

void	op_sa(t_stack *a, t_bench *bench)
{
	swap_stack(a);
	write (1, "sa\n", 3);
	if (bench)
	{
		bench->sa++;
		bench->total++;
	}
}

void	op_sb(t_stack *b, t_bench *bench)
{
	swap_stack(b);
	write (1, "sb\n", 3);
	if (bench)
	{
		bench->sb++;
		bench->total++;
	}
}

void	op_ss(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	swap_stack(a);
	swap_stack(b);
	write (1, "ss\n", 3);
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
}