/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 21:59:26 by ealiman           #+#    #+#             */
/*   Updated: 2026/07/14 23:47:50 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_return(t_stack *a, t_stack *b)
{
	stack_free(a);
	stack_free(b);
}

void	parse_and_fill_stack(int argc, char **argv, t_stack *a, t_bench *bench)
{
	int		num_start;
	int		i;
	int		j;
	char	*token;

	num_start = parse_flags(argc, argv, bench);
	i = argc - 1;
	while (i >= num_start)
	{
		j = count_tokens(argv[i]) - 1;
		while (j >= 0)
		{
			token = get_token_at(argv[i], j);
			if (!token)
				error_exit(a, NULL, bench);
			process_token(token, a, bench);
			j--;
		}
		i--;
	}
}

void	validate_and_prepare(t_stack *a, t_stack *b, t_bench *bench)
{
	if (has_duplicates(a))
		error_exit(a, NULL, bench);
	normalize(a);
	if (stack_is_sorted(a))
	{
		bench->disorder = compute_disorder(a);
		if (bench->enabled)
			print_bench(bench);
		stack_free(a);
		stack_free(b);
		exit(0);
	}
	bench->disorder = compute_disorder(a);
}

void	execute_sort(t_stack *a, t_stack *b, t_bench *bench)
{
	run_sort(a, b, bench);
	if (bench->enabled)
		print_bench(bench);
	//live coding
	// else if (bench->count_only)
	// 	print_bench(bench);
}
