/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:51:44 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/05 16:32:13 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *s, int value, int rank)
{
	t_node	*new_node;

	if (!s)
		return (NULL);
	new_node = create_node(value, rank);
	if (!new_node)
		return (NULL);
	if (s->size == 0)
	{
		s->top = new_node;
		s->bottom = new_node;
		s->size = 1;
	}
	else
	{
		new_node->next = s->top;
		s->top->prev = new_node;
		s->top = new_node;
		s->size++;
	}
}

int	stack_pop_value(t_stack *s)
{
	int	value;
	t_node *curr_node;

	if (!s|| s->size == 0)
		return (0);
	curr_node = s->top;
	value = curr_node->value;
	if (s->size == 1)
	{
		s->top = NULL;
		s->bottom = NULL;
	}
	else
	{
		s->top = curr_node->prev;
		s->top->prev = NULL;
	}
	free(curr_node);
	s->size--;
	return (value);
}

int	stack_pop_rank(t_stack *s)
{}

int	stack_peek_value(t_stack *s)
{}

int	stack_peek_rank(t_stack *s)
{}