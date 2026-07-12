/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:18:27 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 23:36:51 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_of(t_stack *s, t_node *target)
{
	t_node	*curr_node;
	int		position;

	if (!s || s->size == 0)
		return (-1);
	curr_node = s->top;
	position = 0;
	while (curr_node)
	{
		if (curr_node == target)
			return (position);
		position++;
		curr_node = curr_node->next;
	}
	return (-1);
}

int	cost_to_top(t_stack *s, t_node *node)
{
	int	position;
	int	size;

	if (!s || s->size == 0 || !node)
		return (-1);
	if (s->size == 1)
		return (0);
	size = s->size;
	position = position_of(s, node);
	if (position == -1)
		return (-1);
	if (position <= (size / 2))
		return (position);
	return (size - position);
}

int	direction(t_stack *s, t_node *node)
{
	int	position;

	if (!s || s->size == 0 || !node)
		return (-1);
	if (s->size == 1)
		return (0);
	position = position_of(s, node);
	if (position == -1)
		return (0);
	if (position <= (s->size / 2))
		return (1);
	return (-1);
}

void	rotate_to_top(t_stack *s, t_node *node, t_bench *bench, char stack)
{
	int				position;
	t_rotate_info	info;

	if (!s || s->size < 2 || !node)
		return ;
	position = position_of(s, node);
	if (position == -1)
		return ;
	info.stack = stack;
	info.forward = (position <= (s->size / 2));
	rotate_direction(s, node, bench, &info);
}

int	stack_is_sorted(t_stack *s)
{
	t_node	*curr_node;

	if (!s || s->size < 2)
		return (1);
	curr_node = s->top;
	while (curr_node->next)
	{
		if (curr_node->rank > curr_node->next->rank)
			return (0);
		curr_node = curr_node->next;
	}
	return (1);
}
