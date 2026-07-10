#include "../push_swap.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	t_stack	*s;
	float	d;

	/* 1. Stack già ordinato (crescente dal top) → disorder = 0.0 */
	s = stack_init();
	stack_push(s, 4, 0);  // fondo
	stack_push(s, 3, 1);
	stack_push(s, 2, 2);
	stack_push(s, 1, 3);  // top
	d = compute_disorder(s);
	printf("Ordinato: %.2f (atteso 0.00)\n", d);
	assert(d == 0.0f);
	stack_free(s);

	/* 2. Stack inverso (decrescente dal top) → disorder = 1.0 */
	s = stack_init();
	stack_push(s, 1, 0);
	stack_push(s, 2, 1);
	stack_push(s, 3, 2);
	stack_push(s, 4, 3);
	d = compute_disorder(s);
	printf("Inverso: %.2f (atteso 1.00)\n", d);
	assert(d == 1.0f);
	stack_free(s);

	/* 3. Stack misto [3,1,4,2] dal top → disorder = 0.5 */
	s = stack_init();
	stack_push(s, 2, 0);  // fondo
	stack_push(s, 4, 1);
	stack_push(s, 1, 2);
	stack_push(s, 3, 3);  // top
	d = compute_disorder(s);
	printf("Misto: %.2f (atteso 0.50)\n", d);
	assert(d == 0.5f);
	stack_free(s);

	printf("\n✅ Tutti i test passati!\n");
	return (0);
}