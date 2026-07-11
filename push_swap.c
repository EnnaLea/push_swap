/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:27:33 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/11 20:06:51 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a)
		stack_free(a);
	if (b)
		stack_free(b);
	write (2, "Error\n", 6);
	exit(1);
}

int	parse_flags(int argc, char **argv, t_bench *bench)
{
	int i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			bench->enabled = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0)
			bench->strategy = STRATEGY_SIMPLE;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			bench->strategy = STRATEGY_MEDIUM;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			bench->strategy = STRATEGY_COMPLEX;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			bench->strategy = STRATEGY_ADAPTIVE;
		else
			error_exit(NULL, NULL, bench);
		i++;
	}
	return (i);
}

void	run_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size < 2)
		return ;
	else if (a->size == 2)
	{
		if (a->top->rank > a->top->next->rank)
			op_sa(a, bench);
		return ;
	}
	else if (a->size == 3)
	{
		sort_three(a, bench);
		return ;
	}
	if (bench->strategy == STRATEGY_SIMPLE)
		sort_simple(a, b, bench);
	else if (bench->strategy == STRATEGY_MEDIUM)
		sort_medium(a, b, bench);
	else if (bench->strategy == STRATEGY_COMPLEX)
		sort_complex(a, b, bench);
	else
	{
		sort_adaptive(a, b, bench);
	}
}

int push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	int		num_start;
	int		value;
	int		error;
	int		i;

	init_bench(&bench);
	a = stack_init();
	b = stack_init();
	if (!a || !b)
		error_exit(a, b, &bench);
	if (argc == 1)
	{
		stack_free(a);
		stack_free(b);
		return (0);
	}
	num_start = parse_flags(argc, argv, &bench);
	if (num_start >= argc)
	{
		stack_free(a);
		stack_free(b);
		return (0);
	}
	i = argc - 1;
	while (i >= num_start)
	{
		if (!is_number(argv[i]))
			error_exit(a, b, &bench);
		error = 0;
		value = ft_atoi_safe(argv[i], &error);
		if (error)
			error_exit(a, b, &bench);
		stack_push(a, value, 0);
		i--;
	}
	if (has_duplicates(a))
		error_exit(a, b, &bench);
	normalize(a);
	if (stack_is_sorted(a))
	{
		stack_free(a);
		stack_free(b);
		return (0);
	}
	bench.disorder = compute_disorder(a);
	run_sort(a, b, &bench);
	if (bench.enabled)
		print_bench(&bench);
	stack_free(a);
	stack_free(b);
	return (0);
}


