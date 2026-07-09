/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 19:16:50 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/09 19:22:08 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <assert.h>
#include <stdio.h>

static void	print_stack(t_stack *s, const char *name)
{
	t_node	*cur;

	printf("%s (size=%d): ", name, s->size);
	if (!s || s->size == 0)
	{
		printf("vuoto\n");
		return;
	}
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

	/* op_rra: sposta il fondo (3) in cima */
	op_rra(a, &bench);
	print_stack(a, "a dopo rra");
	assert(a->top->value == 3 && a->bottom->value == 2);

	/* op_rrb: sposta il fondo (5) in cima */
	op_rrb(b, &bench);
	print_stack(b, "b dopo rrb");
	assert(b->top->value == 5 && b->bottom->value == 4);

	/* op_rrr: reverse rotate entrambi */
	op_rrr(a, b, &bench);
	print_stack(a, "a dopo rrr");
	print_stack(b, "b dopo rrr");
	assert(a->top->value == 2 && a->bottom->value == 1);
	assert(b->top->value == 4 && b->bottom->value == 5);

	/* Statistiche */
	printf("rra:%d rrb:%d rrr:%d total:%d\n",
		bench.rra, bench.rrb, bench.rrr, bench.total);

	stack_free(a);
	stack_free(b);
	printf("✅ Reverse rotate OK\n");
	return (0);
}