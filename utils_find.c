/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:01:51 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 23:20:26 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_stack *s)
{
	t_node	*curr_node;
	t_node	*min_node;

	if (!s || s->size == 0)
		return (NULL);
	curr_node = s->top;
	min_node = s->top;
	while (curr_node)
	{
		if (curr_node->rank < min_node->rank)
			min_node = curr_node;
		curr_node = curr_node->next;
	}
	return (min_node);
}

t_node	*find_max(t_stack *s)
{
	t_node	*curr_node;
	t_node	*max_node;

	if (!s || s->size == 0)
		return (NULL);
	curr_node = s->top;
	max_node = s->top;
	while (curr_node)
	{
		if (curr_node->rank > max_node->rank)
			max_node = curr_node;
		curr_node = curr_node->next;
	}
	return (max_node);
}

t_node	*find_target_in_b(t_stack *b, int rank)
{
	t_node	*curr_node;
	t_node	*target_node;
	int		right_rank;

	if (!b || b->size == 0)
		return (NULL);
	curr_node = b->top;
	target_node = NULL;
	right_rank = -1;
	while (curr_node)
	{
		if (curr_node->rank < rank && curr_node->rank > right_rank)
		{
			right_rank = curr_node->rank;
			target_node = curr_node;
		}
		curr_node = curr_node->next;
	}
	if (!target_node)
		target_node = find_max(b);
	return (target_node);
}
