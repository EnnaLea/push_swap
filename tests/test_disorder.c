#include "../push_swap.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	t_stack	*s;
	float	d;

	/* 1. Stack ordinato: top → 1 → 2 → 3 → 4 (rank 0,1,2,3) */
	s = stack_init();
	stack_push(s, 4, 3);
	stack_push(s, 3, 2);
	stack_push(s, 2, 1);
	stack_push(s, 1, 0);
	d = compute_disorder(s);
	printf("Ordinato: %.2f (atteso 0.00)\n", d);
	assert(d == 0.0f);
	stack_free(s);

	/* 2. Stack inverso: top → 4 → 3 → 2 → 1 (rank 3,2,1,0) */
	s = stack_init();
	stack_push(s, 1, 0);
	stack_push(s, 2, 1);
	stack_push(s, 3, 2);
	stack_push(s, 4, 3);
	d = compute_disorder(s);
	printf("Inverso: %.2f (atteso 1.00)\n", d);
	assert(d == 1.0f);
	stack_free(s);

	/* 3. Stack misto: top → 3 → 1 → 4 → 2 (rank 2,0,3,1) */
	s = stack_init();
	stack_push(s, 2, 1);  // fondo
	stack_push(s, 4, 3);
	stack_push(s, 1, 0);
	stack_push(s, 3, 2);  // top
	d = compute_disorder(s);
	printf("Misto: %.2f (atteso 0.50)\n", d);
	assert(d == 0.5f);
	stack_free(s);

	printf("\n✅ Tutti i test passati!\n");
	return (0);
}