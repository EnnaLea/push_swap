/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 18:27:52 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/10 19:22:57 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
`1 << bits` equivale a 2^bits. Il loop continua finché 2^bits supera n — a quel punto `bits` è il numero di bit necessari. Con n=500: 2^9=512 > 500, quindi 9 bit.
*/
int	bits_needed(int n)
{
	int bits;
	int tmp;

	bits = 0;
	tmp = n;
	while (tmp > 0)
	{
		bits++;
		tmp = tmp >> 1;
	}
	return (bits);
}

void	radix_pass(t_stack *a, t_stack *b, int bit, t_bench *bench)
{
	int	i;
	int	size;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if ((a->top->rank >> bit) & 1 == 1)
		//bit=1 va in b
			op_pb(a, b, bench);
		else
		//bit=0 va in fondo ad a
			op_ra(a, bench);
		i++;
	}
	while (b->size > 0)
	//rimetti tutto da b in a
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
		radix_pass(a, b, bit,  bench);
		bit++;
	}
}