/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:06:28 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/06 15:10:03 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		printf("vuoto\n");
	curr = s->top;
	if (!curr)
		printf("errore nodo");
	i = 0;
	while (curr)
	{
		printf("[%s] = indice valore = [%d] = rank [%d]\n",
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

	/*Push*/
	stack_push(a, 10, 0);
	stack_push(a, 20, 1);
	stack_push(a, 40, 3);
	print_stack(a, "a");

	assert(a->size == 3);
	assert(a->top->value == 40);
	assert(a->bottom->value == 10);


	return (0);
}
