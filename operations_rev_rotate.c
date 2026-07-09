/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:54:29 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/09 19:23:01 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_stack *s)
{
	t_node	*old_top;
	t_node	*old_bottom;
	t_node	*new_bottom;

	if (!s || s->size < 2)
		return (0);
	old_top = s->top;
	old_bottom = s->bottom;
	new_bottom = s->bottom->prev;
	old_bottom->prev = NULL;
	new_bottom->next = NULL;
	old_bottom->next = old_top;
	old_top->prev = old_bottom;
	s->top = old_bottom;
	s->bottom = new_bottom;
	return (1);
}

void	op_rra(t_stack *a, t_bench *bench)
{
	if (!rev_rotate(a))
		return ;
	write (1, "rra\n", 4);
	if (bench)
	{
		bench->rra++;
		bench->total++;
	}
}

void	op_rrb(t_stack *b, t_bench *bench)
{
	if (!rev_rotate(b))
		return ;
	write (1, "rrb\n", 4);
	if (bench)
	{
		bench->rrb++;
		bench->total++;
	}
}

void	op_rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	int rev_rot_a;
	int	rev_rot_b;

	rev_rot_a = rev_rotate(a);
	rev_rot_b = rev_rotate(b);
	if (!rev_rot_a && !rev_rot_b)
		return;
	write (1, "rrr\n", 4);
	if (bench)
	{
		bench->rrr++;
		bench->total++;
	}

}