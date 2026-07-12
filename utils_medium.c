/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 16:13:24 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/12 18:06:43 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cal_chunk_size(int n)
{
	int	size;

	size = 1;
	while (size * size < n)
		size++;
	return(size);
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

void	process_chunk(t_stack *a, t_stack *b, t_bench *bench,
	int chunk, int chunk_size, int n, int el_in_chunk)
{
	int	pushed;
	int	scanned;

	pushed = 0;
	scanned = 0;
	while (pushed < el_in_chunk)
	{
		if (is_node_in_chunk(a->top, chunk, chunk_size, n))
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
	int	n;
	int	chunk_size;
	int	num_chunks;
	int	chunk;
	int	el_in_chunk;

	if (!a || !b)
		return ;
	n = a->size;
	chunk_size = cal_chunk_size(n);
	num_chunks = (n + chunk_size - 1) / chunk_size;
	chunk = 0;
	while (chunk < num_chunks)
	{
		el_in_chunk = chunk_size;
		if (chunk == num_chunks - 1 && chunk_size != 0)
			el_in_chunk = n % chunk_size;
		process_chunk(a, b, bench, chunk, chunk_size, n, el_in_chunk);
		chunk++;
	}
}

void    push_sorted_to_a(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*max_node;

	while (b->size > 0)
	{
		max_node = find_max(b);
		rotate_to_top(b, max_node, bench, 'b');
		op_pa(a, b, bench);
	}
}
