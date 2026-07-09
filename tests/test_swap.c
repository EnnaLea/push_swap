/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:07:18 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/09 17:36:36 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench = {0};

	a = stack_init();
	b = stack_init();
	assert(a && b);

	/* a: top → 2 → 1 */
	stack_push(a, 1, 0);
	stack_push(a, 2, 1);

	/* b: top → 4 → 3 */
	stack_push(b, 3, 0);
	stack_push(b, 4, 1);

	/* Test sa: scambia i primi due di a */
	op_sa(a, &bench);
	assert(a->top->value == 1 && a->top->next->value == 2);
	assert(bench.sa == 1 && bench.total == 1);

	/* Test sb: scambia i primi due di b */
	op_sb(b, &bench);
	assert(b->top->value == 3 && b->top->next->value == 4);
	assert(bench.sb == 1 && bench.total == 2);

	/* Test ss: scambia entrambi */
	op_ss(a, b, &bench);
	assert(a->top->value == 2 && a->top->next->value == 1);
	assert(b->top->value == 4 && b->top->next->value == 3);
	assert(bench.ss == 1 && bench.total == 3);

	/* Riepilogo */
	printf("sa:%d sb:%d ss:%d total:%d\n", bench.sa, bench.sb, bench.ss, bench.total);
	stack_free(a);
	stack_free(b);
	printf("✅ Test swap passato!\n");
	return (0);
}