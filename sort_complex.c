/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 18:27:52 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/11 20:07:04 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bits_needed(int n)
{
	int	bits;

	bits = 0;
	while ((1 << bits) <= n)
		bits++;
	return (bits);
}

void	radix_pass(t_stack *a, t_stack *b, int bit, t_bench *bench)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((a->top->rank >> bit) & 1) == 1)
			op_pb(a, b, bench);
		else
			op_ra(a, bench);
		i++;
	}
	while (b->size > 0)
		op_pa(a, b, bench);
}

void	sort_complex(t_stack *a, t_stack *b, t_bench *bench)
{
	int	bits;
	int	bit;

	if (stack_is_sorted(a))
		return ;
	if (a->size <= 3)
	{
		sort_three(a, bench);
		return ;
	}
	bits = bits_needed(a->size);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(a, b, bit, bench);
		bit++;
	}
}