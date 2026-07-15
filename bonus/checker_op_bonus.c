/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:57:48 by mcalleja          #+#    #+#             */
/*   Updated: 2026/07/15 11:57:51 by mcalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sh_swap(t_stack *s)
{
	int	tmp_val;

	if (!s || s->size < 2)
		return ;
	tmp_val = s->top->value;
	s->top->value = s->top->next->value;
	s->top->next->value = tmp_val;
	tmp_val = s->top->rank;
	s->top->rank = s->top->next->rank;
	s->top->next->rank = tmp_val;
}

void	sh_push(t_stack *src, t_stack *dest)
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

void	sh_rotate(t_stack *s)
{
	t_node	*top;
	t_node	*bottom;

	if (!s || s->size < 2)
		return ;
	top = s->top;
	bottom = s->bottom;
	s->top = top->next;
	s->top->prev = NULL;
	top->next = NULL;
	bottom->next = top;
	top->prev = bottom;
	s->bottom = top;
}

void	sh_rev_rotate(t_stack *s)
{
	t_node	*top;
	t_node	*bottom;

	if (!s || s->size < 2)
		return ;
	top = s->top;
	bottom = s->bottom;
	s->bottom = bottom->prev;
	s->bottom->next = NULL;
	bottom->prev = NULL;
	bottom->next = top;
	top->prev = bottom;
	s->top = bottom;
}
