/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:56:54 by mcalleja          #+#    #+#             */
/*   Updated: 2026/07/15 11:57:00 by mcalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	bench_inc(t_bench *bench, char *cmd)
{
	if (!bench || !bench->enabled)
		return ;
	if (ft_strcmp(cmd, "sa\n") == 0)
		bench->sa++;
	else if (ft_strcmp(cmd, "sb\n") == 0)
		bench->sb++;
	else if (ft_strcmp(cmd, "ss\n") == 0)
		bench->ss++;
	else if (ft_strcmp(cmd, "pa\n") == 0)
		bench->pa++;
	else if (ft_strcmp(cmd, "pb\n") == 0)
		bench->pb++;
	else if (ft_strcmp(cmd, "ra\n") == 0)
		bench->ra++;
	else if (ft_strcmp(cmd, "rb\n") == 0)
		bench->rb++;
	else if (ft_strcmp(cmd, "rr\n") == 0)
		bench->rr++;
	else if (ft_strcmp(cmd, "rra\n") == 0)
		bench->rra++;
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		bench->rrb++;
	else if (ft_strcmp(cmd, "rrr\n") == 0)
		bench->rrr++;
	bench->total++;
}

static int	execute_cmd_helper(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strcmp(cmd, "pa\n") == 0)
		sh_push(b, a);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		sh_push(a, b);
	else if (ft_strcmp(cmd, "ra\n") == 0)
		sh_rotate(a);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		sh_rotate(b);
	else if (ft_strcmp(cmd, "rr\n") == 0)
	{
		sh_rotate(a);
		sh_rotate(b);
	}
	else if (ft_strcmp(cmd, "rra\n") == 0)
		sh_rev_rotate(a);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		sh_rev_rotate(b);
	else if (ft_strcmp(cmd, "rrr\n") == 0)
	{
		sh_rev_rotate(a);
		sh_rev_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	execute_cmd(char *cmd, t_stack *a, t_stack *b, t_bench *bench)
{
	if (ft_strcmp(cmd, "sa\n") == 0)
		sh_swap(a);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		sh_swap(b);
	else if (ft_strcmp(cmd, "ss\n") == 0)
	{
		sh_swap(a);
		sh_swap(b);
	}
	else if (!execute_cmd_helper(cmd, a, b))
		return (0);
	bench_inc(bench, cmd);
	return (1);
}

int	read_line(char *buffer)
{
	int	i;
	int	done;

	i = 0;
	done = 0;
	while (!done && read(0, buffer + i, 1) > 0)
	{
		if (buffer[i] == '\n')
		{
			i++;
			done = 1;
		}
		else if (i == 9)
			done = 1;
		else
			i++;
	}
	if (i > 0 && buffer[i - 1] != '\n' && i < 9)
	{
		buffer[i] = '\n';
		i++;
	}
	buffer[i] = '\0';
	return (i > 0);
}
