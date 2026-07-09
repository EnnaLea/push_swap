/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:37:25 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/09 17:42:57 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dest)
{
	t_node	*node;
	if (!src || !dest || src->size == 0)
		return ;
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
}

void	op_pa(t_stack *a, t_stack *b, t_bench *bench)
{
	push(b, a);
	write (1, "pa\n", 3);
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
}


void	op_pb(t_stack *a, t_stack *b, t_bench *bench)
{
	push(a, b);
	write (1, "pb\n", 3);
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
}