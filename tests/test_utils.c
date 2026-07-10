/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:34:52 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/10 17:34:53 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	t_stack	*s;
	t_node	*node;
	t_node	*target;
	int		pos;
	int		cost;
	int		dir;

	/* ====== Preparazione stack ====== */
	s = stack_init();
	/* vogliamo: top → 10 (rank 3), 20 (rank 1), 30 (rank 0), 40 (rank 2) */
	stack_push(s, 40, 2);  // fondo
	stack_push(s, 30, 0);
	stack_push(s, 20, 1);
	stack_push(s, 10, 3);  // top

	/* ====== Test position_of ====== */
	target = s->top;  // 10
	pos = position_of(s, target);
	printf("position_of(10) = %d (atteso 0)\n", pos);
	assert(pos == 0);

	target = s->top->next->next;  // 30
	pos = position_of(s, target);
	printf("position_of(30) = %d (atteso 2)\n", pos);
	assert(pos == 2);

	target = s->bottom;  // 40
	pos = position_of(s, target);
	printf("position_of(40) = %d (atteso 3)\n", pos);
	assert(pos == 3);

	/* Nodo non presente */
	printf("position_of(NULL) = %d (atteso -1)\n", position_of(s, NULL));
	assert(position_of(s, NULL) == -1);

	/* ====== Test cost_to_top ====== */
	target = s->top;  // 10, pos=0
	cost = cost_to_top(s, target);
	printf("cost_to_top(10) = %d (atteso 0)\n", cost);
	assert(cost == 0);

	target = s->top->next;  // 20, pos=1
	cost = cost_to_top(s, target);
	printf("cost_to_top(20) = %d (atteso 1)\n", cost);
	assert(cost == 1);

	target = s->bottom;  // 40, pos=3, size=4 → size/2=2, pos>2 → size-pos=1
	cost = cost_to_top(s, target);
	printf("cost_to_top(40) = %d (atteso 1)\n", cost);
	assert(cost == 1);

	/* ====== Test direction ====== */
	target = s->top;  // pos=0 ≤ 2 → 1
	dir = direction(s, target);
	printf("direction(10) = %d (atteso 1, ovvero ra)\n", dir);
	assert(dir == 1);

	target = s->bottom;  // pos=3 > 2 → -1
	dir = direction(s, target);
	printf("direction(40) = %d (atteso -1, ovvero rra)\n", dir);
	assert(dir == -1);

	/* ====== Test stack_is_sorted ====== */
	printf("stack_is_sorted(s) = %d (atteso 0, perché non ordinato)\n", stack_is_sorted(s));
	assert(stack_is_sorted(s) == 0);

	/* Creiamo uno stack ordinato: top → 1,2,3,4 */
	t_stack *sorted = stack_init();
	stack_push(sorted, 4, 3);
	stack_push(sorted, 3, 2);
	stack_push(sorted, 2, 1);
	stack_push(sorted, 1, 0);
	printf("stack_is_sorted(sorted) = %d (atteso 1)\n", stack_is_sorted(sorted));
	assert(stack_is_sorted(sorted) == 1);

	/* ====== Test rotate_to_top (senza bench per non stampare) ====== */
	printf("--- rotate_to_top: portiamo 40 in cima ---\n");
	target = s->bottom;  // 40
	rotate_to_top(s, target, NULL, 'a');
	printf("Top ora ha valore %d (atteso 40)\n", s->top->value);
	assert(s->top->value == 40);

	/* Pulizia */
	stack_free(s);
	stack_free(sorted);

	printf("\n✅ Tutti i test passati!\n");
	return (0);
}