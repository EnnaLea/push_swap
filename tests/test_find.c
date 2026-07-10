/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:15:31 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/10 16:15:41 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	t_stack	*s;
	t_node	*min;
	t_node	*max;

	/* ====== TEST 1: Stack con 4 elementi ====== */
	s = stack_init();
	/* Push in modo che i rank siano: top → 2, 0, 3, 1 */
	stack_push(s, 0, 1);  // fondo
	stack_push(s, 0, 3);
	stack_push(s, 0, 0);
	stack_push(s, 0, 2);  // top

	min = find_min(s);
	max = find_max(s);

	printf("Rank minimo: %d (atteso 0)\n", min ? min->rank : -1);
	printf("Rank massimo: %d (atteso 3)\n", max ? max->rank : -1);

	assert(min && min->rank == 0);
	assert(max && max->rank == 3);

	stack_free(s);

	/* ====== TEST 2: Stack con 1 elemento ====== */
	s = stack_init();
	stack_push(s, 0, 5);

	min = find_min(s);
	max = find_max(s);

	/* La funzione restituisce NULL per size < 2 */
	assert(min == NULL);
	assert(max == NULL);

	stack_free(s);

	/* ====== TEST 3: Stack vuoto ====== */
	s = stack_init();

	min = find_min(s);
	max = find_max(s);

	assert(min == NULL);
	assert(max == NULL);

	stack_free(s);

	printf("\n✅ Tutti i test passati!\n");
	return (0);
}