/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 16:13:24 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 23:07:08 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cal_chunk_size(int n)
{
	int	size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}

int	is_node_in_chunk(t_node *node, int chunk, int chunk_size, int n)
{
	int	c_min;
	int	c_max;

	c_min = chunk * chunk_size;
	c_max = (chunk + 1) * (chunk_size - 1);
	if (c_max >= n)
		c_max = n - 1;
	return (node->rank >= c_min && node->rank <= c_max);
}

void	process_chunk(t_stack *a, t_stack *b,
	t_bench *bench, t_chunk_info *info)
{
	int	pushed;
	int	scanned;

	pushed = 0;
	scanned = 0;
	while (pushed < info->el_in_chunk)
	{
		if (is_node_in_chunk(a->top, info->chunk, info->chunk_size, info->n))
		{
			if (b->size > 1 && b->top->rank < b->top->next->rank)
				op_rb(b, bench);
			op_pb(a, b, bench);
			pushed++;
			scanned = 0;
		}
		else
		{
			op_ra(a, bench);
			scanned++;
			if (scanned >= a->size)
				break ;
		}
	}
}

void	push_chunks_to_b(t_stack *a, t_stack *b, t_bench *bench)
{
	t_chunk_info	info;
	int				chunk;
	int				num_chunks;

	if (!a || !b)
		return ;
	info.n = a->size;
	info.chunk_size = cal_chunk_size(info.n);
	num_chunks = (info.n + info.chunk_size - 1) / info.chunk_size;
	chunk = 0;
	while (chunk < num_chunks)
	{
		info.chunk = chunk;
		info.el_in_chunk = info.chunk_size;
		if (chunk == num_chunks - 1 && info.chunk_size != 0)
			info.el_in_chunk = info.n % info.chunk_size;
		process_chunk(a, b, bench, &info);
		chunk++;
	}
}

void	push_sorted_to_a(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*max_node;

	while (b->size > 0)
	{
		max_node = find_max(b);
		rotate_to_top(b, max_node, bench, 'b');
		op_pa(a, b, bench);
	}
}
