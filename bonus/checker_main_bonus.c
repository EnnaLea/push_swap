/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealiman <ealiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:58:17 by mcalleja          #+#    #+#             */
/*   Updated: 2026/07/15 13:00:28 by ealiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker_error(t_stack *a, t_stack *b)
{
	if (a)
		stack_free(a);
	if (b)
		stack_free(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	message_resoult(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	char	cmd[10];

	if (argc < 2)
		return (0);
	init_bench(&bench);
	a = stack_init();
	b = stack_init();
	if (!a || !b)
		checker_error(a, b);
	parse_and_fill_stack(argc, argv, a, &bench);
	if (a->size == 0 || has_duplicates(a))
		checker_error(a, b);
	normalize(a);
	while (read_line(cmd))
	{
		if (!execute_cmd(cmd, a, b, &bench))
			checker_error(a, b);
	}
	message_resoult(a, b);
	return (stack_free(a), stack_free(b), 0);
}
