/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_op_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:46:03 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/09 18:47:47 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <assert.h>
#include <stdio.h>

static void	print_stack(t_stack *s, const char *name)
{
	t_node	*cur;

	printf("%s (size=%d): ", name, s->size);
	cur = s->top;
	while (cur)
	{
		printf("%d", cur->value);
		if (cur->next)
			printf(" → ");
		cur = cur->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench = {0};

	a = stack_init();
	b = stack_init();
	assert(a && b);

	/* a: top → 1 → 2 → 3 */
	stack_push(a, 3, 0);
	stack_push(a, 2, 1);
	stack_push(a, 1, 2);

	/* b: top → 4 → 5 */
	stack_push(b, 5, 0);
	stack_push(b, 4, 1);

	printf("--- Iniziale ---\n");
	print_stack(a, "a");
	print_stack(b, "b");

	/* op_ra: sposta 1 in fondo */
	op_ra(a, &bench);
	print_stack(a, "a dopo ra");
	assert(a->top->value == 2 && a->bottom->value == 1);

	/* op_rb: sposta 4 in fondo */
	op_rb(b, &bench);
	print_stack(b, "b dopo rb");
	assert(b->top->value == 5 && b->bottom->value == 4);

	/* op_rr: ruota entrambi */
	op_rr(a, b, &bench);
	print_stack(a, "a dopo rr");
	print_stack(b, "b dopo rr");
	assert(a->top->value == 3 && a->bottom->value == 2);
	assert(b->top->value == 4 && b->bottom->value == 5);

	/* Statistiche bench */
	printf("ra:%d rb:%d rr:%d total:%d\n",
		bench.ra, bench.rb, bench.rr, bench.total);

	stack_free(a);
	stack_free(b);
	printf("✅ Rotazioni OK\n");
	return (0);
}