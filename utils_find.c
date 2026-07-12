/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:01:51 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 12:23:12 by ealiman          ###   ########.fr       */
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