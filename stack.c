/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:37:43 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/08 09:28:22 by ealiman          ###   ########.fr       */
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
{
	return (!s || s->size == 0);
}

t_node	*stack_get_at(t_stack *s, int i)
{
	t_node	*curr_node;
	int		j;

	if (!s || i < 0 || i >= s->size)
		return (NULL);
	curr_node = s->top;
	j = 0;
	while (j < i)
	{
		curr_node = curr_node->next;
		if(!curr_node)
			return (NULL);
		j++;
	}
	return (curr_node);
}

void	stack_free(t_stack *s)
{
	t_node	*curr_node;
	t_node	*next_node;

	if (!s)
		return ;
	curr_node = s->top;
	while (curr_node)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
	free(s);
}