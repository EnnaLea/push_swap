/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:06:28 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/08 09:38:24 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
#include <assert.h>

void	print_stack(t_stack *s, const char *name)
{
	t_node	*curr;
	int		i;

	if (!s)
	{
		printf("%s: (NULL)/\n", name);
		return;
	}
	printf("%s (size = %d)\n", name, s->size);
	if (s->size == 0)
	{
		printf("vuoto\n");
		return;
	}
	curr = s->top;
	if (!curr)
		printf("errore nodo");
	i = 0;
	while (curr)
	{
		printf("[%d] = indice valore = [%d] = rank [%d]\n",
		i, curr->value, curr->rank);
		if (curr->next)
			printf("<->");
		curr = curr->next;
		i++;
	}
	printf("\n");
}

int	main(void)
{
	t_node	*node;
	t_stack	*a;
	t_stack	*b;
	int		value;
	int		rank;

	printf("==== TEST STACK ====\n\n");

	a = stack_init();
	b = stack_init();
	printf("------ Inizializzati stack a e stack b ------\n");
	print_stack(a, "a");
	print_stack(b, "b");
	assert(a != NULL);
	assert(b != NULL);
	assert(stack_is_empty(a) == 1);

	/*Push stack a*/
	printf("\n2. Push su a: 10(r=0), 20(r=1), 30(r=2), 40(r=3)\n");
	stack_push(a, 10, 0);
	stack_push(a, 20, 1);
	stack_push(a, 30, 2);
	stack_push(a, 40, 3);
	print_stack(a, "a");

	assert(a->size == 4);
	assert(a->top->value == 40);
	assert(a->bottom->value == 10);

	/*Push stack b*/
	printf("\n3. Push su b: 100(r=10), 200(r=20)\n");
	stack_push(b, 100, 10);
	stack_push(b, 200, 20);
	print_stack(b, "b");
	assert(b->size == 2);

	/*Peek valore e rank*/
	printf("\nPeek di a: valore = %d, rank = %d",
		stack_peek_value(a), stack_peek_rank(a));
	assert(stack_peek_value(a) == 40);
	assert(stack_peek_rank(a) == 3);

	/*Pop con rank e value*/
	printf("\nPop da a:\n");
	value = 0;
	rank = 0;
	stack_pop(a, &value, &rank);
	printf("Estratto valore = %d e rank = %d\n", value, rank);
	assert(value == 40);
	assert(rank == 3);
	print_stack(a, "a dopo pop");
	assert(a->size == 3);
	assert(a->top->value == 30);

	/*Stack_get_at*/
	printf("\nStack_get_at su a:\n");
	node = stack_get_at(a, 0);
	if (node)
		printf("indice 0: valore = %d, rank = %d\n",
		node->value, node->rank);
	node = stack_get_at(a, 1);
	if (node)
		printf("indice 1: valore = %d, rank = %d\n",
		node->value, node->rank);
	node = stack_get_at(a, 2);
	if (node)
		printf("indice 2: valore = %d, rank = %d\n",
		node->value, node->rank);
	assert(stack_get_at(a, 0)->value == 30);
	assert(stack_get_at(a, 1)->value == 20);
	assert(stack_get_at(a, 2)->value == 10);

	/* 8. Push su a dopo pop */
	printf("\n8. Push 50 su a:\n");
	stack_push(a, 50, 4);
	print_stack(a, "a");
	assert(a->size == 4);
	assert(a->top->value == 50);

	/* 9. Test stack_is_empty */
	printf("\n9. stack_is_empty su a e b:\n");
	printf("   a vuoto? %s\n", stack_is_empty(a) ? "sì" : "no");
	printf("   b vuoto? %s\n", stack_is_empty(b) ? "sì" : "no");
	assert(stack_is_empty(a) == 0);
	assert(stack_is_empty(b) == 0);

	/* 10. Svuotare completamente b */
	printf("\n10. Svuotare b con pop:\n");
	while (!stack_is_empty(b))
	{
		value = stack_pop(b, NULL, NULL);
		printf("   pop: %d\n", value);
	}
	print_stack(b, "b");
	assert(stack_is_empty(b) == 1);

	/* 11. Pop da stack vuoto (dovrebbe restituire 0) */
	printf("\n11. Pop da b vuoto:\n");
	value = stack_pop(b, value, rank);
	printf("   valore restituito: %d (dovrebbe essere 0)\n", value);
	assert(value == 0);

	/* 12. Liberazione memoria */
	printf("\n12. Liberazione di a e b\n");
	stack_free(a);
	stack_free(b);
	printf("   Memoria liberata.\n");
	printf("\n=== TUTTI I TEST PASSATI ===\n");
	return (0);
}
