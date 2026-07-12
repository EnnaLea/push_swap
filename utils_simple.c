/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 10:56:33 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 23:20:18 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	calc_cost(t_stack *a, t_stack *b, t_node *node)
{
	t_node	*target_node;
	int		cost_a;
	int		cost_b;
	int		dir_a;
	int		dir_b;

	target_node = find_target_in_b(b, node->rank);
	cost_a = cost_to_top(a, node);
	dir_a = direction(a, node);
	if (!target_node)
		return ((cost_a + 1));
	cost_b = cost_to_top(b, target_node);
	dir_b = direction(b, target_node);
	if (dir_a == dir_b)
		return (ft_max(cost_a, cost_b) + 1);
	else
		return ((cost_a + cost_b) + 1);
}

t_node	*find_cheapest(t_stack *a, t_stack *b)
{
	t_node	*curr_node;
	t_node	*cheapest;
	int		min_cost;
	int		cost;

	curr_node = a->top;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (curr_node)
	{
		cost = calc_cost(a, b, curr_node);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = curr_node;
		}
		curr_node = curr_node->next;
	}
	return (cheapest);
}

void	execute_move(t_stack *a, t_stack *b, t_node *node, t_bench *bench)
{
	t_node	*target_node;
	int		dir_a;
	int		dir_b;

	target_node = find_target_in_b(b, node->rank);
	dir_a = direction(a, node);
	if (!target_node)
		dir_b = 0;
	else
		dir_b = direction(b, target_node);
	if (dir_a == 1 && dir_b == 1)
	{
		while (a->top != node && b->top != target_node)
			op_rr(a, b, bench);
	}
	else if (dir_a == -1 && dir_b == -1)
	{
		while (a->top != node && b->top != target_node)
			op_rrr(a, b, bench);
	}
	rotate_to_top(a, node, bench, 'a');
	if (target_node)
		rotate_to_top(b, target_node, bench, 'b');
	op_pb(a, b, bench);
}

void	push_back_to_a(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*max_node;

	while (b->size > 0)
	{
		max_node = find_max(b);
		rotate_to_top(b, max_node, bench, 'b');
		op_pa(a, b, bench);
	}
}
