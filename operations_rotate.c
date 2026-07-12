/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:46:35 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 23:30:47 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *s)
{
	t_node	*old_top;
	t_node	*new_top;
	t_node	*old_bottom;

	if (!s || s->size < 2)
		return (0);
	old_top = s->top;
	old_bottom = s->bottom;
	new_top = s->top->next;
	new_top->prev = NULL;
	old_top->next = NULL;
	old_bottom->next = old_top;
	old_top->prev = old_bottom;
	s->top = new_top;
	s->bottom = old_top;
	return (1);
}

void	op_ra(t_stack *a, t_bench *bench)
{
	if (rotate(a))
	{
		write (1, "ra\n", 3);
		if (bench && bench->enabled)
		{
			bench->ra++;
			bench->total++;
		}
	}
}

void	op_rb(t_stack *b, t_bench *bench)
{
	if (rotate(b))
	{
		write (1, "rb\n", 3);
		if (bench && bench->enabled)
		{
			bench->rb++;
			bench->total++;
		}
	}
}

void	op_rr(t_stack *a, t_stack *b, t_bench *bench)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(a);
	rotated_b = rotate(b);
	if (rotated_a && rotated_b)
	{
		write (1, "rr\n", 3);
		if (bench && bench->enabled)
		{
			bench->rr++;
			bench->total++;
		}
	}
}

void	rotate_direction(t_stack *s, t_node *node, t_bench *bench,
	t_rotate_info *info)
{
	if (info->forward)
	{
		while (s->top != node)
		{
			if (info->stack == 'a')
				op_ra(s, bench);
			else
				op_rb(s, bench);
		}
	}
	else
	{
		while (s->top != node)
		{
			if (info->stack == 'a')
				op_rra(s, bench);
			else
				op_rrb(s, bench);
		}
	}
}
