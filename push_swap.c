/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:27:33 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/14 23:45:52 by ealiman          ###   ########.fr       */
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
	int	i;

	i = 1;
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
		//live coding
		// else if (ft_strcmp(argv[i], "--count-only") == 0)
		// 	bench->count_only = 1;
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
		sort_adaptive(a, b, bench);
}

static void	process_stack(t_stack *a, t_stack *b,
	t_bench *bench, t_cmd_args *cmd)
{
	parse_and_fill_stack(cmd->argc, cmd->argv, a, bench);
	if (a->size == 0)
		return ;
	if (has_duplicates(a))
		error_exit(a, b, bench);
	normalize(a);
	if (stack_is_sorted(a))
	{
		bench->disorder = compute_disorder(a);
		if (bench->enabled)
			print_bench(bench);
		return ;
	}
	bench->disorder = compute_disorder(a);
	execute_sort(a, b, bench);
}

int	push_swap(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;
	t_cmd_args	cmd;

	init_bench(&bench);
	a = stack_init();
	b = stack_init();
	if (!a || !b)
		error_exit(a, b, &bench);
	if (argc == 1)
	{
		free_and_return(a, b);
		return (0);
	}
	cmd.argc = argc;
	cmd.argv = argv;
	process_stack(a, b, &bench, &cmd);
	stack_free(a);
	stack_free(b);
	return (0);
}
