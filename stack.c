/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:37:43 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/05 16:02:30 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
	return (s);
}

t_node	*create_node(int value, int rank)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->rank = rank;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	stack_is_empty(t_stack *s)
{}

t_node	*stack_get_at(t_stack *s, int i)
{}

void	stack_free(t_stack *s)
{}