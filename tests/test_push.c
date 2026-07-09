/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:43:52 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/09 17:45:13 by ealiman          ###   ########.fr       */
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

	/* a: top → 3 → 2 → 1 */
	stack_push(a, 1, 0);
	stack_push(a, 2, 1);
	stack_push(a, 3, 2);

	/* b: vuoto */
	printf("--- Push 3 a -> b (pb) ---\n");
	op_pb(a, b, &bench);
	assert(a->size == 2 && b->size == 1);
	assert(a->top->value == 2);
	assert(b->top->value == 3);
	assert(bench.pb == 1 && bench.total == 1);

	printf("--- Push 3 b -> a (pa) ---\n");
	op_pa(a, b, &bench);
	assert(a->size == 3 && b->size == 0);
	assert(a->top->value == 3);
	assert(bench.pa == 1 && bench.total == 2);

	/* Riepilogo */
	printf("pa:%d pb:%d total:%d\n", bench.pa, bench.pb, bench.total);

	stack_free(a);
	stack_free(b);
	printf("✅ Test push passato!\n");
	return (0);
}