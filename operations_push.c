/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:37:25 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/14 17:06:42 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack *src, t_stack *dest)
{
	t_node	*node;

	if (!src || !dest || src->size == 0)
		return (0);
	node = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	node->next = dest->top;
	node->prev = NULL;
	if (dest->top)
		dest->top->prev = node;
	else
		dest->bottom = node;
	dest->top = node;
	dest->size++;
	return (1);
}

void	op_pa(t_stack *a, t_stack *b, t_bench *bench)
{
	if (push(b, a))
	{
		write (1, "pa\n", 3);
		if (bench && bench->enabled)
		{
			bench->pa++;
			bench->total++;
		}
	}
}

void	op_pb(t_stack *a, t_stack *b, t_bench *bench)
{
	if (push(a, b))
	{
		write (1, "pb\n", 3);
		if (bench && bench->enabled)
		{
			bench->pb++;
			bench->total++;
		}
	}
}
